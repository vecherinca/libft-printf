/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:37:14 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 19:12:58 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushto_median(t_a_list *start, t_head_a *b, t_head_a *a, int median)
{
	if (start->index <= median)
	{
		pb(a, b);
		rb(b, 1);
	}
	else
		pb(a, b);
}

void	presort(int median, t_head_a *b, t_head_a *a)
{
	int			maximum;
	t_a_list	*start;

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
