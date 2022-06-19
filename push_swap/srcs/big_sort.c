#include "../includes/push_swap.h"

ssize_t	find_idx_max_elem(t_list *stk)
{
	t_list	*max_list;
	t_list	*tmp_list;

	max_list = stk;
	tmp_list = stk->next;
	while (tmp_list)
	{
		if (max_list->num < tmp_list->num)
			max_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	return (max_list->idx);
}

void	ft_work_stack_a(t_stack *cnf)
{
	ssize_t	flag_generation;

	flag_generation = cnf->stk_a->flag;
	if (cnf->stk_a->flag != 0)
	{
		while (cnf->stk_a->flag == flag_generation)
		{
			if (cnf->stk_a->idx == cnf->min)
				ft_rotate_min_elem(cnf);
			else
				ft_push(&cnf->stk_a, &cnf->stk_b, "pb", cnf);
			ft_work_min_elem(cnf);
		}
	}
	else if (cnf->stk_a->flag == 0)
	{
		while (cnf->stk_a->flag != -1)
		{
			if (cnf->stk_a->idx == cnf->min)
				ft_rotate_min_elem(cnf);
			else
				ft_push(&cnf->stk_a, &cnf->stk_b, "pb", cnf);
			ft_work_min_elem(cnf);
		}
	}
}

void	ft_work_stack_b(t_stack *cnf)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(cnf->stk_b);
	while (i < size && cnf->stk_b != NULL)
	{
		if (cnf->stk_b->idx == cnf->min)
			ft_work_min_elem(cnf);
		else if (cnf->stk_b->idx >= cnf->mid)
		{
			cnf->stk_b->flag = cnf->flag;
			ft_push(&cnf->stk_b, &cnf->stk_a, "pa", cnf);
		}
		else
			ft_rotate(&cnf->stk_b, "rb", cnf);
		i++;
	}
}

static void	ft_div_stack_a(t_stack *cnf)
{
	int		i;
	ssize_t	size_a;
	ssize_t	size_b;

	i = 0;
	size_a = ft_lstsize(cnf->stk_a);
	while (i < size_a)
	{
		if (cnf->stk_a->idx > cnf->mid)
		{
			size_b = ft_lstsize(cnf->stk_b);
			if (size_b >= 2 && cnf->stk_b->idx < cnf->mid / 2)
				ft_rotate_all(&cnf->stk_a, &cnf->stk_b, cnf);
			else
				ft_rotate(&cnf->stk_a, "ra", cnf);
		}
		else if (cnf->stk_a->idx <= cnf->mid)
			ft_push(&cnf->stk_a, &cnf->stk_b, "pb", cnf);
		i++;
	}
}

void	ft_big_sort(t_stack *cnf)
{
	cnf->min = 0;
	cnf->max = cnf->size_a - 1;
	cnf->mid = cnf->max / 2 + 1;
	while (cnf->min < cnf->size_a)
	{
		if (cnf->flag == 0)
		{
			ft_div_stack_a(cnf);
			cnf->mid = (cnf->mid - cnf->min) / 2 + cnf->min;
			cnf->flag += 1;
		}
		else if (cnf->stk_b != NULL)
		{
			ft_work_stack_b(cnf);
			cnf->mid = (cnf->mid - cnf->min) / 2 + cnf->min;
			cnf->flag += 1;
		}
		else if (cnf->stk_b == NULL)
		{
			ft_work_stack_a(cnf);
			if (cnf->stk_b != NULL)
				cnf->max = find_idx_max_elem(cnf->stk_b);
			cnf->mid = (cnf->max - cnf->min) / 2 + cnf->min;
		}
	}
}
