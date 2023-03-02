/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:43:07 by maria             #+#    #+#             */
/*   Updated: 2023/03/01 17:43:19 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(head_a *heada, head_a *headb)
{
	a_list	*starta;

	starta = heada->first;
	heada->first = starta->next;
	starta->next = headb->first;
	headb->first = starta;
	write(1, "pb\n", 3);
}

void	pa(head_a *heada, head_a *headb)
{
	a_list	*startb;

	startb = headb->first;
	headb->first = startb->next;
	startb->next = heada->first;
	heada->first = startb;
	write(1, "pa\n", 3);
}
