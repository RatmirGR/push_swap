#include "../includes/push_swap.h"

static void	ft_sort2(t_list **s, t_stack *cnf)
{
	if ((*s)->num > (*s)->next->num)
		ft_swap(s, "sa", cnf);
}

static void	ft_sort3(t_list **s, t_stack *cnf)
{
	int	ar[3];

	ft_set_arr(s, ar, 3);
	if (ar[0] < ar[1] && ar[0] < ar[2])
	{
		ft_rev_rotate(s, "rra", cnf);
		ft_swap(s, "sa", cnf);
	}
	ft_set_arr(s, ar, 3);
	if (ar[1] < ar[0] && ar[1] < ar[2])
	{
		if (ar[0] < ar[2])
			ft_swap(s, "sa", cnf);
		else
			ft_rotate(s, "ra", cnf);
	}
	ft_set_arr(s, ar, 3);
	if (ar[2] < ar[0] && ar[2] < ar[1])
	{
		if (ar[0] > ar[1])
			ft_swap(s, "sa", cnf);
		ft_rev_rotate(s, "rra", cnf);
	}
}

static void	ft_sort4(t_stack *cnf)
{
	int	ar[4];

	ft_set_arr(&cnf->stk_a, ar, 4);
	if (ar[1] < ar[0] && ar[1] < ar[2] && ar[1] < ar[3])
	{
		ft_swap(&cnf->stk_a, "sa", cnf);
		ft_set_arr(&cnf->stk_a, ar, 4);
	}
	if (ar[2] < ar[0] && ar[2] < ar[1] && ar[2] < ar[3])
	{
		ft_rev_rotate(&cnf->stk_a, "rra", cnf);
		ft_rev_rotate(&cnf->stk_a, "rra", cnf);
		ft_set_arr(&cnf->stk_a, ar, 4);
	}
	if (ar[3] < ar[0] && ar[3] < ar[1] && ar[3] < ar[2])
	{
		ft_rev_rotate(&cnf->stk_a, "rra", cnf);
		ft_set_arr(&cnf->stk_a, ar, 4);
	}
	if (!(ar[0] < ar[1] && ar[1] < ar[2] && ar[2] < ar[3]))
	{
		ft_push(&cnf->stk_a, &cnf->stk_b, "pb", cnf);
		ft_sort3(&cnf->stk_a, cnf);
		ft_push(&cnf->stk_b, &cnf->stk_a, "pa", cnf);
	}
}

static void	ft_sort5(t_stack *cnf)
{
	int	ar[5];

	ft_set_arr(&cnf->stk_a, ar, 5);
	if (ar[1] < ar[0] && ar[1] < ar[2] && ar[1] < ar[3] && ar[1] < ar[4])
	{
		ft_swap(&cnf->stk_a, "sa", cnf);
		ft_set_arr(&cnf->stk_a, ar, 5);
	}
	if (ar[2] < ar[0] && ar[2] < ar[1] && ar[2] < ar[3] && ar[2] < ar[4])
		ft_count_rotate(cnf, 2, ar, 5);
	if (ar[3] < ar[0] && ar[3] < ar[1] && ar[3] < ar[2] && ar[3] < ar[4])
		ft_count_rev_rotate(cnf, 2, ar, 5);
	if (ar[4] < ar[0] && ar[4] < ar[1] && ar[4] < ar[2] && ar[4] < ar[3])
		ft_count_rev_rotate(cnf, 1, ar, 5);
	if (!(ar[0] < ar[1] && ar[1] < ar[2] && ar[2] < ar[3] && ar[3] < ar[4]))
	{
		ft_push(&cnf->stk_a, &cnf->stk_b, "pb", cnf);
		ft_sort4(cnf);
		ft_push(&cnf->stk_b, &cnf->stk_a, "pa", cnf);
	}
}

void	ft_small_sort(t_stack *cnf)
{
	if (cnf->size_a == 2)
		ft_sort2(&cnf->stk_a, cnf);
	else if (cnf->size_a == 3)
		ft_sort3(&cnf->stk_a, cnf);
	else if (cnf->size_a == 4)
		ft_sort4(cnf);
	if (cnf->size_a == 5)
		ft_sort5(cnf);
}
