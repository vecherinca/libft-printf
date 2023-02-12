/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:29 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/12 19:25:07 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushto_median(a_list *start, head_a *b, head_a *a, int median)
{
	if (start -> index <= median)
	{
		pb(a, b);
		rb(b, 1);
	}
	else
		pb(a, b);
}

void presort(int median, head_a *b, head_a *a)
{
	int maximum;
	a_list *start;
	start = a->first;
	//i think it's -1 for sure but check lol
	maximum = ft_lstsize(start) - 1;
	while (start -> next != NULL)
	{
		if (start -> index != maximum)
			pushto_median(start, b, a, median);
		else
			rra(a, 1);
		start = a->first;
	}
}

void test_instr(head_a *a,head_a *b)
{
	// here what I want to do is for every node
	// write the number of functions
	a_list *start_a;
	a_list *start_b;
	
	algo_values count_a;
	algo_values count_b;

	start_a = a -> first;
	start_b = b -> first;
	
	while (start_b -> next != NULL)
	{
		
		
	}
}

void sort100(head_a *a,head_a *b)
{
	int median;
	a_list *start;
	start = a -> first;
	median = ft_lstsize(start)/2;
	//printf("MEDIAN ----> %d\n", median);
	presort(median, b, a);
	test_instr(a, b);
}