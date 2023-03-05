/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:43:07 by maria             #+#    #+#             */
/*   Updated: 2023/03/04 01:53:06 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void	pb(head_a *heada, head_a *headb)
{
	a_list	*starta;

	starta = heada->first;
	heada->first = starta->next;
	starta->next = headb->first;
	headb->first = starta;
}

void	pa(head_a *heada, head_a *headb)
{
	a_list	*startb;

	startb = headb->first;
	headb->first = startb->next;
	startb->next = heada->first;
	heada->first = startb;
}
