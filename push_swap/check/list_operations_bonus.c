/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:21:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/06 20:16:13 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

int	ft_lstsize(t_a_list *lst)
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

void	ft_lstadd_back(t_a_list **lst, t_a_list *new)
{
	t_a_list	*tmp;

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

t_a_list	*ft_lstlast(t_a_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_a_list	*findsecondlastnode(t_a_list *head)
{
	t_a_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->next->next == NULL)
			return (temp);
		temp = temp->next;
	}
	return (0);
}

int	check_doubl(t_head_a *heada)
{
	t_a_list	*start;
	t_a_list	*temp;
	int			count;

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
