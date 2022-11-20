/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:48:53 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/20 18:08:27 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!*lst)
	{
		*lst = new;
		return ;
	}
	t_list	*tmp;
	tmp = *lst;
	while (tmp -> next != NULL)
		tmp = tmp->next;
	tmp -> next = new;
	// why don't we need to point new to NULL??? wtf? 
}