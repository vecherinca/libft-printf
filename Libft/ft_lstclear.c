/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:48:43 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/20 20:29:31 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{

	t_list *temp;
	temp = *lst;
	
	while (temp != NULL) // this one is ok
	{	
		temp = temp -> next;
		del((*lst)->content); // with this one 
		free(*lst);
		*lst = temp;
		
	}
	*lst = NULL;
}