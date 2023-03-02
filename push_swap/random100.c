/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:29 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/02 01:59:09 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_instr(head_a *a, head_a *b)
{
	a_list		*start_b;
	algo_values	current;
	algo_values	next_node;

	current.node = b->first;
	start_b = b->first;
	while (start_b)
	{
		current = number_moves(a, start_b, b, current);
		while (start_b != NULL)
		{
			next_node = number_moves(a, start_b, b, next_node);
			if (calc_instructions(current, next_node) == 1)
				current = next_node;
			start_b = start_b->next;
		}
		movefastest(current, a, b);
		pa(a, b);
		start_b = b->first;
	}
}

void	zero_zero(algo_values go_zero, head_a *a)
{
	while (go_zero.rra != 0)
	{
		rra(a, 1);
		go_zero.rra--;
	}
	while (go_zero.ra != 0)
	{
		ra(a, 1);
		go_zero.ra--;
	}
}

void	push_zero(head_a *a, a_list *zero)
{
	int			size;
	int			count;
	algo_values	go_zero;
	a_list		*starta;

	starta = a->first;
	size = ft_lstsize(starta);
	count = 0;
	go_zero.ra = 0;
	go_zero.rra = 0;
	while (starta != zero)
	{
		count++;
		starta = starta->next;
	}
	if (count <= size / 2)
		go_zero.ra = count;
	else if (count > size / 2)
		go_zero.rra = size - count;
	zero_zero(go_zero, a);
}

void	sort100(head_a *a, head_a *b)
{
	int		median;
	a_list	*zero;
	a_list	*start;

	start = a->first;
	zero = find_min(start);
	median = ft_lstsize(start) / 2;
	presort(median, b, a);
	test_instr(a, b);
	push_zero(a, zero);
}
