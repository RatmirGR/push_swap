#include "../includes/push_swap.h"

static void	ft_init_config(t_stack **cnf)
{
	*cnf = NULL;
	*cnf = malloc(sizeof(t_stack));
	if (*cnf == NULL)
		ft_print_error(NULL, ERROR_MEM, "1");
	(*cnf)->stk_a = NULL;
	(*cnf)->stk_b = NULL;
	(*cnf)->arr = NULL;
	(*cnf)->arr_cmd = NULL;
	(*cnf)->tmp_cmd = NULL;
	(*cnf)->idx_cmd = 0;
	(*cnf)->max_cmd = 1;
	(*cnf)->flag = 0;
	(*cnf)->min = 0;
	(*cnf)->next = 0;
}

ssize_t	ft_is_sort_stack(t_list *stk)
{
	t_list	*tmp;
	int		min;

	if (stk != NULL)
	{
		min = stk->num;
		tmp = stk->next;
		if (tmp != NULL)
		{
			while (tmp != NULL)
			{
				if (min < tmp->num)
					min = tmp->num;
				else
					return (0);
				tmp = tmp->next;
			}
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*cnf;
	ssize_t	i;

	ft_init_config(&cnf);
	if (ft_validate_args(cnf, argc, argv) == 0)
	{
		if (cnf->stk_a != NULL && (ft_is_sort_stack(cnf->stk_a) != 1))
		{
			cnf->size_a = ft_lstsize(cnf->stk_a);
			ft_create_sort_arr(cnf);
			ft_full_stack_idx(cnf);
			if (cnf->size_a <= 5)
				ft_small_sort(cnf);
			else
				ft_big_sort(cnf);
			ft_optimization_cmd(cnf);
			i = -1;
			while (cnf->arr_cmd[++i] != NULL)
				if (ft_strcmp(cnf->arr_cmd[i], "del") != 0)
					ft_print_cmd(cnf->arr_cmd[i]);
		}
	}
	ft_free(cnf);
	return (0);
}
