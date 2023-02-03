/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:59:44 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/02 19:10:36 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list find_min_next()
{
	
}
void	assign_index(head_a *a)
{
	int size;
	int i;
	int min;
	a_list *start;

	start = a -> first;
	i = 0;
	size = ft_lstsize(start);

	while (i < size)
	{
		min = find_min(start);
		while (start -> content > min && start -> next != NULL)
		{
			
		}
	}
		
}