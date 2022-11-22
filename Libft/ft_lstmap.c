/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:51:27 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/22 21:54:31 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		len;
	t_list	*output;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		output -> next = ft_lstnew(f(lst -> content));
		lst = lst -> next;
	}
	return (output);
}
