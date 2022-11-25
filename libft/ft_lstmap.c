/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:51:27 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/25 18:35:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’.
How it works:
1)We create two t_list objects.
2)Assigning to a new node the modified content.
3)If something is wrong with the assignment we clear the list we going to return.
4)If everything is ok, adding the nodes from the end. 
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*node;

	if (!lst)
		return (NULL);
	output = 0;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst -> content));
		if (!node)
			ft_lstclear(&output, del);
		ft_lstadd_back(&output, node);
		lst = lst -> next;
	}
	return (output);
}
