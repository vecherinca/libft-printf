/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:21:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/21 21:51:32 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstdelone(a_list *lst, void (del)(int))
{
	if (!lst || !del)
		return ;
	del (lst -> content);
	free(lst);
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
	while (tmp -> next != NULL)
		tmp = tmp->next;
	tmp -> next = new;
}

a_list	*ft_lstlast(a_list *lst)
{
	//a_list	*prev;
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

a_list *findsecondlastnode(a_list *head)
{
	a_list *temp;
	temp = head;
	while(temp != NULL)
	{
		if (temp->next->next == NULL)
            return (temp);
		temp = temp->next;
	}
	return(0);
}
