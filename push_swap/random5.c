/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:30 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/27 14:19:16 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort5(head_a *a, head_a *b)
{
	a_list *start;
	a_list *min;
	a_list *temp;
	
	start = a -> first;
	min = find_min(start);
	pushmin(a, min -> content);
	if (min -> next == NULL)
		temp = a -> first;
	else
		temp = min -> next;
	pb(a, b);
	min = find_min(temp);
	pushmin(a, min -> content);
	pb(a, b);	
	sort3(a);
	pa(a, b);
	pa(a, b);
}

a_list *find_min(a_list *start)
{
	a_list *min;
	min = start;
	while (start != NULL)
	{
		if (start -> content < min -> content)
		{
			//node = start;
			min = start;
		}
		start = start -> next;
	}
	return(min);
}

void pushmin(head_a *a, int min)
{
	a_list *start;
	
	start = a -> first;
	while (start -> content != min)
	{
		ra(a);
		start = a -> first;
	}
	// printf("END\n");
}