/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefastest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:10:56 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 19:11:22 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_algo_values	max_pul_rr(t_algo_values current)
{
	current.rr = 0;
	if (current.rb > current.ra && current.ra > 0)
	{
		current.rr = current.ra;
		current.ra = 0;
		current.rb = current.rb - current.rr;
	}
	if (current.ra > current.rb && current.rb > 0)
	{
		current.rr = current.rb;
		current.rb = 0;
		current.ra = current.ra - current.rr;
	}
	if (current.ra == current.rb && (current.ra > 0 && current.rb > 0))
	{
		current.rr = current.rb;
		current.rb = 0;
		current.ra = 0;
	}
	return (current);
}

t_algo_values	max_pull_rrr(t_algo_values current)
{
	current.rrr = 0;
	if (current.rrb > current.rra && current.rra > 0)
	{
		current.rrr = current.rra;
		current.rra = 0;
		current.rrb = current.rrb - current.rrr;
	}
	if (current.rra > current.rrb && current.rrb > 0)
	{
		current.rrr = current.rrb;
		current.rrb = 0;
		current.rra = current.rra - current.rrr;
	}
	if (current.rra == current.rrb && (current.rra > 0 && current.rrb > 0))
	{
		current.rrr = current.rrb;
		current.rrb = 0;
		current.rra = 0;
	}
	return (current);
}

void	run_rotate(t_algo_values current, t_head_a *a, t_head_a *b)
{
	while (current.rr != 0)
	{
		rr(a, b);
		current.rr--;
	}
	while (current.ra != 0)
	{
		ra(a, 1);
		current.ra--;
	}
	while (current.rb != 0)
	{
		rb(b, 1);
		current.rb--;
	}
}

void	run_reverse_rotate(t_algo_values current, t_head_a *a, t_head_a *b)
{
	while (current.rrr != 0)
	{
		rrr(a, b);
		current.rrr--;
	}
	while (current.rra != 0)
	{
		rra(a, 1);
		current.rra--;
	}
	while (current.rrb != 0)
	{
		rrb(b, 1);
		current.rrb--;
	}
}

void	movefastest(t_algo_values current, t_head_a *a, t_head_a *b)
{
	current = max_pul_rr(current);
	current = max_pull_rrr(current);
	run_rotate(current, a, b);
	run_reverse_rotate(current, a, b);
}
