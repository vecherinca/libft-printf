/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:43:07 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 19:12:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void	pb(t_head_a *heada, t_head_a *headb)
{
	t_a_list	*starta;

	starta = heada->first;
	heada->first = starta->next;
	starta->next = headb->first;
	headb->first = starta;
}

void	pa(t_head_a *heada, t_head_a *headb)
{
	t_a_list	*startb;

	startb = headb->first;
	headb->first = startb->next;
	startb->next = heada->first;
	heada->first = startb;
}
