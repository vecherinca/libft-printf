/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:59:44 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/10 16:56:32 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_next(a_list *start, int min)
{
	int new_min;
	
	new_min = start -> content;
	while (start != NULL)
	{
		if ((start -> content < new_min) && (start -> content > min))
			new_min = start -> content;
		start = start -> next;
	}
	return(new_min);
}
void	assign_index(head_a *a)
{
	int size;
	int i;
	int minmin;
	a_list *min;
	a_list *start;

	start = a -> first;
	i = 0;
	size = ft_lstsize(start);
	min = find_min(start);
	minmin = min -> content;
	
	while (i < size)
	{
		while (start -> next!= NULL)
		{
			if (start -> content >= minmin)
			{
				start -> index = i;
			}
			start = start -> next;
		}
		// this shit is not working you need to check the last case
		start -> index = i;
		start = a -> first;
		minmin = find_min_next(start, minmin);
		i++;
	}
}