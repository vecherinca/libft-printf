/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:25:13 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/25 18:10:09 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
This function adds the node ’new’ at the beginning of the list.
How this function works:
1)Linking new node to first mode In order to *lst become the second node.
2)Head pointer must point to a "new" adress because it has changed. 
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = (*lst);
	*lst = new;
}
