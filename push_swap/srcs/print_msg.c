#include "../includes/push_swap.h"

void	ft_free(t_stack *cnf)
{
	if (cnf != NULL)
	{
		ft_lstclear(&cnf->stk_a);
		ft_lstclear(&cnf->stk_b);
		free(cnf->arr);
		free(cnf->arr_cmd);
		free(cnf);
	}
}

void	ft_print_error(t_stack *cnf, char *desc, char *name)
{
	write(2, "Error\n", 6);
	write(2, desc, ft_strlen(desc));
	write(2, ": ", 2);
	write(2, name, ft_strlen(name));
	write(2, "\n", 1);
	ft_free(cnf);
	exit(1);
}

void	ft_print_cmd(char *name_cmd)
{
	ssize_t	len;

	len = ft_strlen(name_cmd);
	write(1, name_cmd, len);
	write(1, "\n", 1);
}
