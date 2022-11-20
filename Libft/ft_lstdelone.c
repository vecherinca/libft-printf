/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:20:03 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/20 18:23:49 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// lst c'est adress of the node to free
// 
void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	free(lst);
}