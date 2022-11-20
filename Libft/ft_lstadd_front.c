/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:25:13 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/19 20:01:12 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// maybe need to add some checks

void ft_lstadd_front(t_list **lst, t_list *new) //it's already allocated value to add???
{
	new-> next = (*lst); // this shit is: new points to head node
	*lst = new; // here we say that now the adress of the first position is the adress of a node new
	
}