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
}

static ssize_t	ft_is_sort_stack(t_list *stk)
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

static void	ft_run_cmd(t_stack *cnf, char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		ft_swap(&cnf->stk_a, "sa", cnf);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_swap(&cnf->stk_b, "sb", cnf);
	else if (ft_strcmp(cmd, "ss") == 0)
		ft_swap_all(&cnf->stk_a, &cnf->stk_b, cnf);
	else if (ft_strcmp(cmd, "ra") == 0)
		ft_rotate(&cnf->stk_a, "ra", cnf);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_rotate(&cnf->stk_b, "rb", cnf);
	else if (ft_strcmp(cmd, "rr") == 0)
		ft_rotate_all(&cnf->stk_a, &cnf->stk_b, cnf);
	else if (ft_strcmp(cmd, "rra") == 0)
		ft_rev_rotate(&cnf->stk_a, "rra", cnf);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_rev_rotate(&cnf->stk_b, "rrb", cnf);
	else if (ft_strcmp(cmd, "rrr") == 0)
		ft_rev_rotate_all(&cnf->stk_a, &cnf->stk_b, cnf);
	else if (ft_strcmp(cmd, "pa") == 0)
		ft_push(&cnf->stk_b, &cnf->stk_a, "pa", cnf);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_push(&cnf->stk_a, &cnf->stk_b, "pb", cnf);
	else
		ft_print_error(cnf, INVALID_CMD, "1");
}

int	main(int argc, char *argv[])
{
	t_stack	*cnf;
	char	*cmd;

	ft_init_config(&cnf);
	if (ft_validate_args(cnf, argc, argv) == 0)
	{
		if (cnf->stk_a != NULL)
		{
			cmd = get_next_line(0);
			while (cmd != NULL)
			{
				ft_run_cmd(cnf, cmd);
				free(cmd);
				cmd = get_next_line(0);
			}
			if (cnf->stk_b == NULL && ft_is_sort_stack(cnf->stk_a) == 1)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
	}
	ft_free(cnf);
	return (0);
}
