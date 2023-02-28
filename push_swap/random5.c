/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:30 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/01 00:29:07 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort5(head_a *a, head_a *b, int flag)
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
	if (flag == 5)
	{
		min = find_min(temp);
		pushmin(a, min -> content);
		pb(a, b);	
		sort3(a);
		pa(a, b);
		pa(a, b);
	}
	if (flag == 4)
	{
		sort3(a);
		pa(a, b);
	}
}

a_list *find_min(a_list *start)
{
	a_list *min;
	min = start;
	while (start != NULL)
	{
		if (start -> content < min -> content)
			min = start;
		start = start -> next;
	}
	return(min);
}
// ./a.out 5 -1 -3 45 7
//./a.out 5 1000 8 0 -1
void pushmin(head_a *a, int min)
{
	a_list *start;
	int count;
	int len;

	
	count = 0;
	start = a -> first;
	len = ft_lstsize(start);
	while (start -> content != min)
	{
		count++;
		start = start->next;
	}
	start = a -> first;
	while (start -> content != min)
	{
		if (count <= len/2)
			ra(a, 1);
		if (count > len/2)
			rra(a, 1);
		start = a->first;
	}
	// printf("END\n");
}