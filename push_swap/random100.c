/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:29 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/10 23:39:12 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushto_median(a_list *start, head_a *b, head_a *a, int median)
{
	if (start -> index < median)
	{
		pb(a, b);
		rb(b);
	}
	else
		pb(a, b);
	
}

void presort(int median, head_a *b, head_a *a)
{
	int maximum;
	a_list *start;
	start = a->first;
	//i think it's -1 for sure
	maximum = ft_lstsize(start) - 1;

	while (start -> next != NULL)
	{
		if (start -> index != maximum)
		{
			pushto_median(start, b, a, median);
		}
		else
			rra(a);
		start = a->first;
	}
	
}

void sort100(head_a *a,head_a *b)
{
	int median;
	a_list *start;
	start = a -> first;
	median = ft_lstsize(start)/2;
	printf("MEDIAN ----> %d\n", median);
	presort(median, b, a);
	
}