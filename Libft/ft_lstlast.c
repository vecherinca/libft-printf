/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:43:52 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/20 18:13:58 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 t_list *ft_lstlast(t_list *lst)
 {
	if (!lst)
		return(NULL);
	
	while (lst -> next != NULL)
		lst = lst -> next; 
	return(lst); // idk if it's okay
 }