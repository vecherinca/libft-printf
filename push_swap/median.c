/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:37:14 by maria             #+#    #+#             */
/*   Updated: 2023/03/02 01:36:50 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushto_median(a_list *start, head_a *b, head_a *a, int median)
{
	if (start->index <= median)
	{
		pb(a, b);
		rb(b, 1);
	}
	else
		pb(a, b);
}

void	presort(int median, head_a *b, head_a *a)
{
	int		maximum;
	a_list	*start;

	start = a->first;
	maximum = ft_lstsize(start) - 1;
	while (start->next != NULL)
	{
		if (start->index != maximum)
			pushto_median(start, b, a, median);
		else
			ra(a, 1);
		start = a->first;
	}
}
