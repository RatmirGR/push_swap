#include "../includes/push_swap.h"

void	ft_set_arr(t_list **s, int *arr, ssize_t size)
{
	ssize_t	i;
	t_list	*stk;

	stk = *s;
	i = 0;
	while (i < size)
	{
		arr[i] = stk->num;
		stk = stk->next;
		i++;
	}
}

void	ft_count_rev_rotate(t_stack *cnf, ssize_t count, int *ar, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < count)
	{
		ft_rev_rotate(&cnf->stk_a, "rra", cnf);
		i++;
	}
	ft_set_arr(&cnf->stk_a, ar, size);
}

void	ft_count_rotate(t_stack *cnf, ssize_t count, int *ar, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < count)
	{
		ft_rotate(&cnf->stk_a, "ra", cnf);
		i++;
	}
	ft_set_arr(&cnf->stk_a, ar, size);
}

static void	ft_copy_arr_cmd(t_stack *cnf)
{
	ssize_t	i;

	i = 0;
	if (cnf->arr_cmd == NULL)
		ft_print_error(cnf, ERROR_MEM, "1");
	cnf->arr_cmd[cnf->max_cmd] = NULL;
	while (i < cnf->max_cmd / 2)
	{
		cnf->arr_cmd[i] = cnf->tmp_cmd[i];
		i++;
	}
	free(cnf->tmp_cmd);
}

void	ft_check_arr_cmd(t_stack *cnf, char *name_cmd)
{
	if (cnf->idx_cmd + 2 > cnf->max_cmd)
	{
		if (cnf->idx_cmd == 0)
		{
			cnf->max_cmd = 1000;
			cnf->arr_cmd = malloc((cnf->max_cmd + 1) * sizeof(char *));
		}
		else
		{
			cnf->tmp_cmd = cnf->arr_cmd;
			cnf->max_cmd *= 2;
			cnf->arr_cmd = malloc((cnf->max_cmd + 1) * sizeof(char *));
			ft_copy_arr_cmd(cnf);
		}
		if (cnf->arr_cmd == NULL)
			ft_print_error(cnf, ERROR_MEM, "1");
		cnf->arr_cmd[cnf->max_cmd] = NULL;
		cnf->arr_cmd[cnf->idx_cmd++] = name_cmd;
	}
	else
		cnf->arr_cmd[cnf->idx_cmd++] = name_cmd;
}
