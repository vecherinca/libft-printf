/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:51:27 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/23 19:49:56 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
