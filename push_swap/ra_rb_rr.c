/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:42:02 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 19:12:58 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_head_a *heada, int flag)
{
	t_a_list	*starta;
	t_a_list	*finish;
	t_a_list	*seconda;

	starta = heada->first;
	if (ft_lstsize(starta) > 1)
	{
		finish = ft_lstlast(starta);
		seconda = heada->first->next;
		heada->first = seconda;
		finish->next = starta;
		starta->next = NULL;
		if (flag != 0)
			write(1, "ra\n", 3);
	}
}

void	rb(t_head_a *headb, int flag)
{
	t_a_list	*startb;
	t_a_list	*finish;
	t_a_list	*seconda;

	startb = headb->first;
	if (ft_lstsize(startb) > 1)
	{
		finish = ft_lstlast(startb);
		seconda = headb->first->next;
		headb->first = seconda;
		finish->next = startb;
		startb->next = NULL;
		if (flag != 0)
			write(1, "rb\n", 3);
	}
}

void	rr(t_head_a *heada, t_head_a *headb)
{
	if (ft_lstsize(heada->first) > 1 && ft_lstsize(headb->first) > 1)
	{
		ra(heada, 0);
		rb(headb, 0);
		write(1, "rr\n", 3);
	}
}
