#include "../includes/push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->num = num;
		list->next = NULL;
		list->idx = 0;
		list->flag = 0;
	}
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			last = *lst;
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
		lst = NULL;
	}
}
