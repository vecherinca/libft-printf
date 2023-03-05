/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:52:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 19:12:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void	rra(t_head_a *heada)
{
	t_a_list	*starta;
	t_a_list	*finish;
	t_a_list	*prev;

	starta = heada->first;
	if (ft_lstsize(starta) > 1)
	{
		prev = findsecondlastnode(starta);
		finish = ft_lstlast(starta);
		heada->first = finish;
		prev->next = NULL;
		finish->next = starta;
	}
}

void	rrb(t_head_a *headb)
{
	t_a_list	*startb;
	t_a_list	*finish;
	t_a_list	*prev;

	startb = headb->first;
	if (ft_lstsize(startb) > 1)
	{
		prev = findsecondlastnode(startb);
		finish = ft_lstlast(startb);
		headb->first = finish;
		prev->next = NULL;
		finish->next = startb;
	}
}

void	rrr(t_head_a *heada, t_head_a *headb)
{
	if (ft_lstsize(heada->first) > 1 && ft_lstsize(headb->first) > 1)
	{
		rra(heada);
		rrb(headb);
	}
}
