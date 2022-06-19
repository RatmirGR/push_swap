#include "../includes/push_swap.h"

void	ft_rotate_min_elem(t_stack *cnf)
{
	cnf->stk_a->flag = -1;
	ft_rotate(&cnf->stk_a, "ra", cnf);
	cnf->min++;
}

static t_list	*find_last_min(t_list *stk)
{
	t_list	*tmp;

	if (stk == NULL)
		return (NULL);
	tmp = stk;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_move_min_elem_v1(t_stack *cnf)
{
	cnf->stk_b->flag = -1;
	ft_push(&cnf->stk_b, &cnf->stk_a, "pa", cnf);
	ft_rotate(&cnf->stk_a, "ra", cnf);
	cnf->min++;
}

void	ft_move_min_elem_v2(t_stack *cnf)
{
	ft_swap_all(&cnf->stk_a, &cnf->stk_b, cnf);
	ft_rotate_min_elem(cnf);
}

void	ft_work_min_elem(t_stack *cnf)
{
	cnf->tmp_flag = 1;
	while (cnf->tmp_flag == 1)
	{
		cnf->size_b = ft_lstsize(cnf->stk_b);
		if (cnf->size_b > 0 && cnf->stk_b->idx == cnf->min)
			ft_move_min_elem_v1(cnf);
		else if (cnf->size_b > 1 && cnf->stk_a->next->idx == cnf->min
			&& cnf->stk_b->next->idx == cnf->min + 1)
			ft_move_min_elem_v2(cnf);
		else if (cnf->size_b > 2 && find_last_min(cnf->stk_b)->idx == cnf->min)
		{
			ft_rev_rotate(&cnf->stk_b, "rrb", cnf);
			ft_push(&cnf->stk_b, &cnf->stk_a, "pa", cnf);
			ft_rotate_min_elem(cnf);
		}
		else if (cnf->stk_a->idx == cnf->min)
			ft_rotate_min_elem(cnf);
		else if (cnf->stk_a->next->idx == cnf->min)
		{
			ft_swap(&cnf->stk_a, "sa", cnf);
			ft_rotate_min_elem(cnf);
		}
		else
			cnf->tmp_flag = 0;
	}
}
