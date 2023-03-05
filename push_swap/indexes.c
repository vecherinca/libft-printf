/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:59:44 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 20:10:52 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_next(t_a_list *start, int min)
{
	int	new_min;

	new_min = find_max(start);
	while (start != NULL)
	{
		if ((start->content < new_min) && (start->content > min))
			new_min = start->content;
		start = start->next;
	}
	return (new_min);
}

int	find_max(t_a_list *start)
{
	t_a_list	*max;

	max = start;
	while (start != NULL)
	{
		if (start->content > max->content)
			max = start;
		start = start->next;
	}
	return (max->content);
}

void	assign_index(t_head_a *a)
{
	int			size;
	int			i;
	int			minmin;
	t_a_list	*min;
	t_a_list	*start;

	start = a->first;
	i = 0;
	size = ft_lstsize(start);
	min = find_min(start);
	minmin = min->content;
	while (i < size)
	{
		while (start != NULL)
		{
			if (start->content >= minmin)
				start->index = i;
			start = start->next;
		}
		start = a->first;
		minmin = find_min_next(start, minmin);
		i++;
	}
}
