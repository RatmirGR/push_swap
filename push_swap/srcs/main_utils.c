#include "../includes/push_swap.h"

static void	ft_sort_arr(t_stack	*cnf, int *arr, int left, int right)
{
	int	l_bor;
	int	r_bor;

	l_bor = left;
	r_bor = right;
	cnf->pivot = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= cnf->pivot)
			right--;
		if (left != right)
			arr[left++] = arr[right];
		while (left < right && arr[left] <= cnf->pivot)
			left++;
		if (left != right)
			arr[right--] = arr[left];
	}
	arr[left] = cnf->pivot;
	cnf->pivot = left;
	left = l_bor;
	right = r_bor;
	if (left < cnf->pivot)
		ft_sort_arr(cnf, arr, left, cnf->pivot -1);
	if (right > cnf->pivot)
		ft_sort_arr(cnf, arr, cnf->pivot + 1, right);
}

void	ft_create_sort_arr(t_stack *cnf)
{
	ssize_t	i;
	t_list	*stk;

	cnf->arr = malloc(cnf->size_a * sizeof(int));
	if (cnf->arr == NULL)
		ft_print_error(cnf, ERROR_MEM, "1");
	i = 0;
	stk = cnf->stk_a;
	while (stk != NULL)
	{
		cnf->arr[i] = stk->num;
		stk = stk->next;
		i++;
	}
	ft_sort_arr(cnf, cnf->arr, 0, cnf->size_a - 1);
}

void	ft_full_stack_idx(t_stack *cnf)
{
	ssize_t	i;
	t_list	*stk;

	stk = cnf->stk_a;
	while (stk != NULL)
	{
		i = 0;
		while (i < cnf->size_a)
		{
			if (cnf->arr[i] == stk->num)
				stk->idx = i;
			i++;
		}
		stk = stk->next;
	}
}

static void	ft_remove_element(t_stack *cnf, ssize_t *idx, char *cmd)
{
	cnf->arr_cmd[*idx] = cmd;
	cnf->arr_cmd[*idx + 1] = "del";
	(*idx)++;
}

void	ft_optimization_cmd(t_stack *cnf)
{
	ssize_t	i;
	char	*cmd1;
	char	*cmd2;

	i = 0;
	while (cnf->arr_cmd[i + 1] != NULL)
	{
		cmd1 = cnf->arr_cmd[i];
		cmd2 = cnf->arr_cmd[i + 1];
		if (ft_strcmp(cmd1, "sa") == 0 && ft_strcmp(cmd2, "sb") == 0)
			ft_remove_element(cnf, &i, "ss");
		if (ft_strcmp(cmd1, "ra") == 0 && ft_strcmp(cmd2, "rb") == 0)
			ft_remove_element(cnf, &i, "rr");
		if (ft_strcmp(cmd1, "rra") == 0 && ft_strcmp(cmd2, "rrb") == 0)
			ft_remove_element(cnf, &i, "rrr");
		i++;
	}
}
