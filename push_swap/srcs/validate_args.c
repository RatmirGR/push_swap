#include "../includes/push_swap.h"

static void	ft_get_node(t_stack *cnf, char *c_num, ssize_t idx)
{
	int		num;
	t_list	*node;
	t_list	*tmp;

	num = ft_atoi(c_num);
	if (cnf->stk_a == NULL)
	{
		cnf->stk_a = ft_lstnew(num);
		cnf->stk_a->idx = idx;
		cnf->stk_a->flag = 0;
	}
	else
	{
		tmp = cnf->stk_a;
		while (tmp != NULL)
		{
			if (tmp->num == num)
				ft_print_error(cnf, DUPLICATE_ARG, "1");
			tmp = tmp->next;
		}
		node = ft_lstnew(num);
		node->idx = idx;
		node->flag = 0;
		ft_lstadd_back(&cnf->stk_a, node);
	}
}

static ssize_t	ft_is_invalid_int(char *c_num)
{
	long	num;

	num = ft_atoi(c_num);
	if (num > MAX_INT || num < MIN_INT)
		return (1);
	return (0);
}

static void	ft_validate_arr(t_stack *cnf, char *arr[], int size)
{
	ssize_t	i;
	ssize_t	len;

	i = 1;
	while (i < size)
	{
		len = ft_strlen(arr[i]);
		if (len == 0)
			ft_print_error(cnf, INVALID_ARGS, "1");
		if (len == 1 && (arr[i][0] < '0' || arr[i][0] > '9'))
			ft_print_error(cnf, INVALID_ARGS, "1");
		else if (len > 1 && ft_atoi(arr[i]) == 0)
			ft_print_error(cnf, INVALID_ARGS, "1");
		else if (len > 1 && ft_is_invalid_int(arr[i]) == 1)
			ft_print_error(NULL, OUT_INT, "1");
		else
			ft_get_node(cnf, arr[i], i);
		i++;
	}
}

static ssize_t	ft_is_space(char *arg)
{
	ssize_t	i;
	char	*arr;

	arr = malloc(6 * sizeof(char));
	if (arr == NULL)
		return (1);
	arr[0] = ' ';
	arr[1] = '\n';
	arr[2] = '\t';
	arr[3] = '\f';
	arr[4] = '\r';
	arr[5] = '\v';
	i = 0;
	while (i < 6)
	{
		if (ft_strchr(arg, arr[i]) != NULL)
		{
			free(arr);
			return (1);
		}
		i++;
	}
	free(arr);
	return (0);
}

int	ft_validate_args(t_stack *cnf, int ac, char *av[])
{
	ssize_t	len;

	if (ac < 2)
		return (1);
	else if (ac == 2)
	{
		len = ft_strlen(av[1]);
		if (len == 0)
			ft_print_error(cnf, INVALID_ARGS, "1");
		if (len == 1 && (av[1][0] < '0' || av[1][0] > '9'))
			ft_print_error(cnf, INVALID_ARGS, "1");
		if (len > 1)
		{
			if (ft_is_space(av[1]) == 1)
				ft_print_error(cnf, INVALID_ARGS, "1");
			else if (ft_atoi(av[1]) == 0)
				ft_print_error(NULL, INVALID_ARGS, "1");
			else if (ft_is_invalid_int(av[1]) == 1)
				ft_print_error(NULL, OUT_INT, "1");
		}
	}
	else
		ft_validate_arr(cnf, av, ac);
	return (0);
}
