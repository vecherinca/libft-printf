/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:21:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/04 01:35:41 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

int	ft_lstsize(a_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstadd_back(a_list **lst, a_list *new)
{
	a_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

a_list	*ft_lstlast(a_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

a_list	*findsecondlastnode(a_list *head)
{
	a_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->next->next == NULL)
			return (temp);
		temp = temp->next;
	}
	return (0);
}

int	check_doubl(head_a *heada)
{
	a_list	*start;
	a_list	*temp;
	int		count;

	count = 0;
	start = heada->first;
	while (start->next != NULL)
	{
		temp = start->next;
		while (temp != NULL)
		{
			if (start->content == temp->content)
			{
				count++;
				return (0);
			}
			temp = temp->next;
		}
		start = start->next;
	}
	return (1);
}
