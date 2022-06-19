#include "../includes/push_swap.h"

void	ft_rev_rotate_all(t_list **stk_a, t_list **stk_b, t_stack *cnf)
{
	ft_rev_rotate(stk_a, "rrr", cnf);
	ft_rev_rotate(stk_b, "rrr", cnf);
	ft_check_arr_cmd(cnf, "rrr");
}

void	ft_rotate_all(t_list **stk_a, t_list **stk_b, t_stack *cnf)
{
	ft_rotate(stk_a, "rr", cnf);
	ft_rotate(stk_b, "rr", cnf);
	ft_check_arr_cmd(cnf, "rr");
}

void	ft_swap_all(t_list **stk_a, t_list **stk_b, t_stack *cnf)
{
	ft_swap(stk_a, "ss", cnf);
	ft_swap(stk_b, "ss", cnf);
	ft_check_arr_cmd(cnf, "ss");
}
