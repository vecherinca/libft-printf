/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:52:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/01 17:42:23 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(head_a *heada, int flag)
{
	a_list	*starta;
	a_list	*finish;
	a_list	*prev;

	starta = heada->first;
	if (ft_lstsize(starta) > 1)
	{
		prev = findsecondlastnode(starta);
		finish = ft_lstlast(starta);
		heada->first = finish;
		prev->next = NULL;
		finish->next = starta;
		if (flag != 0)
			write(1, "rra\n", 4);
	}
}

void	rrb(head_a *headb, int flag)
{
	a_list	*startb;
	a_list	*finish;
	a_list	*prev;

	startb = headb->first;
	if (ft_lstsize(startb) > 1)
	{
		prev = findsecondlastnode(startb);
		finish = ft_lstlast(startb);
		headb->first = finish;
		prev->next = NULL;
		finish->next = startb;
		if (flag != 0)
			write(1, "rrb\n", 4);
	}
}

void	rrr(head_a *heada, head_a *headb)
{
	if (ft_lstsize(heada->first) > 1 && ft_lstsize(headb->first) > 1)
	{
		rra(heada, 0);
		rrb(headb, 0);
		write(1, "rrr\n", 4);
	}
}
