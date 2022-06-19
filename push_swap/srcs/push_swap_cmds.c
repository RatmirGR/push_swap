#include "../includes/push_swap.h"

void	ft_swap(t_list **stk, char *name_cmd, t_stack *cnf)
{
	t_list	*tmp;
	ssize_t	size;

	size = 0;
	if (*stk != NULL)
		size = ft_lstsize(*stk);
	if (size > 1)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		tmp->next = (*stk)->next;
		(*stk)->next = tmp;
		if (name_cmd != NULL)
			if (ft_strnstr("sa", name_cmd, 2) || ft_strnstr("sb", name_cmd, 2))
				ft_check_arr_cmd(cnf, name_cmd);
	}
}

void	ft_push(t_list **stk_1, t_list **stk_2, char *name_cmd, t_stack *cnf)
{
	ssize_t	size;
	t_list	*tmp;

	size = ft_lstsize(*stk_1);
	if (size > 0)
	{
		tmp = *stk_1;
		*stk_1 = (*stk_1)->next;
		tmp->next = *stk_2;
		*stk_2 = tmp;
		if (name_cmd != NULL)
			if (ft_strnstr("pa", name_cmd, 2) || ft_strnstr("pb", name_cmd, 2))
				ft_check_arr_cmd(cnf, name_cmd);
	}
}

void	ft_rotate(t_list **stk, char *name_cmd, t_stack *cnf)
{
	t_list	*tmp;
	t_list	*last;
	ssize_t	size;

	size = 0;
	if (*stk != NULL)
		size = ft_lstsize(*stk);
	if (size > 1)
	{
		last = *stk;
		tmp = *stk;
		*stk = (*stk)->next;
		while (last->next != NULL)
			last = last->next;
		tmp->next = NULL;
		last->next = tmp;
		if (name_cmd != NULL)
			if (ft_strnstr("ra", name_cmd, 2) || ft_strnstr("rb", name_cmd, 2))
				ft_check_arr_cmd(cnf, name_cmd);
	}
}

void	ft_rev_rotate(t_list **stk, char *cmd, t_stack *cnf)
{
	t_list	*tmp;
	t_list	*last;
	ssize_t	size;

	size = 0;
	if (*stk != NULL)
		size = ft_lstsize(*stk);
	if (size > 1)
	{
		last = *stk;
		tmp = *stk;
		while (last->next != NULL)
			last = last->next;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *stk;
		*stk = last;
		if (cmd != NULL)
			if (ft_strnstr("rra", cmd, 3) || ft_strnstr("rrb", cmd, 3))
				ft_check_arr_cmd(cnf, cmd);
	}
}
