/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:42:02 by maria             #+#    #+#             */
/*   Updated: 2023/03/04 15:57:53 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void	ra(head_a *heada)
{
	a_list	*starta;
	a_list	*finish;
	a_list	*seconda;

	starta = heada->first;
	if (ft_lstsize(starta) > 1)
	{
		finish = ft_lstlast(starta);
		seconda = heada->first->next;
		heada->first = seconda;
		finish->next = starta;
		starta->next = NULL;
	}
}

void	rb(head_a *headb)
{
	a_list	*startb;
	a_list	*finish;
	a_list	*seconda;

	startb = headb->first;
	if (ft_lstsize(startb) > 1)
	{
		finish = ft_lstlast(startb);
		seconda = headb->first->next;
		headb->first = seconda;
		finish->next = startb;
		startb->next = NULL;
	}
}

void	rr(head_a *heada, head_a *headb)
{
	if (ft_lstsize(heada->first) > 1 && ft_lstsize(headb->first) > 1)
	{
		ra(heada);
		rb(headb);
	}
}
