/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:30 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/25 23:47:36 by mklimina         ###   ########.fr       */
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
	//printf("FIRST MIN ----> %d\n", min -> content);
	pushmin(a, min -> content);
	temp = min -> next;
	pb(a, b);
	min = find_min(temp);
	pushmin(a, min -> content);
	pb(a, b);	
	sort3(a);
	pa(a, b);
	pa(a, b);
	//printf("second MIN ----> %d\n", min -> content);
	
	//printf("temp node ----> %d\n", temp ---> content);
	//pushmin(a, min -> content);
	// pb(a, b);
}

a_list *find_min(a_list *start)
{
	int min;
	a_list *node;
	
	min = start -> content;
	while (start != NULL)
	{
		if (start -> content < min)
		{
			node = start;
			min = start -> content;
		}
		start = start -> next;
	}
	return(node);
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