/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:48:53 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/25 17:47:56 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
This function adds the node ’new’ at the end of the list.
The idea behind code: 
1) if we have nothing in a list we just assign new to lst. 
2) while we are not at the end of the list (tmp -> next) the loop is looping
3) when we reach the last position we assign new to the last position
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

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
