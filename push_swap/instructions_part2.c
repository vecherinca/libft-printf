/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:52:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/27 03:24:14 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void ra(head_a *heada, int flag)
{
	a_list *starta;
	a_list *finish;
	a_list *seconda;
	
	starta = heada -> first;
	if(ft_lstsize(starta) > 1)
	{
		finish = ft_lstlast(starta);
		seconda = heada -> first -> next;
		heada -> first = seconda;
		finish -> next = starta;
		starta -> next = NULL;
		if (flag != 0)
			write(1, "ra\n", 3);
	}
}

/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/

void rb(head_a *headb, int flag)
{
	a_list *startb;
	a_list *finish;
	a_list *seconda;
	startb = headb -> first;
	if(ft_lstsize(startb) > 1)
	{
		finish = ft_lstlast(startb);
		seconda = headb -> first -> next;
		headb -> first = seconda;
		finish -> next = startb;
		startb -> next = NULL;
		if (flag != 0)
			write(1, "rb\n", 3);
	}
}

/**rr : ra and rb at the same time.**/
// check the number of elements
void rr(head_a *heada, head_a *headb)
{
	ra(heada, 0);
	rb(headb, 0);
	write(1, "rr\n", 3);
}
/**rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.**/ 
void rra(head_a *heada, int flag)
{
	a_list *starta; 
	a_list *finish;
	a_list *prev;
	starta = heada -> first;
	if(ft_lstsize(starta) > 1)
	{
		prev = findsecondlastnode(starta);
		finish = ft_lstlast(starta);
		heada -> first = finish;
		prev -> next = NULL;
		finish -> next = starta;
		if (flag != 0)
			write(1, "rra\n", 4);
	}
}

/**rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first on**/
void rrb(head_a *headb, int flag)
{
	a_list *startb;
	a_list *finish;
	a_list *prev;
	startb = headb -> first;
	if(ft_lstsize(startb) > 1)
	{
		prev = findsecondlastnode(startb);
		finish = ft_lstlast(startb);
		headb -> first = finish;
		prev -> next = NULL;
		finish -> next = startb;
		if (flag != 0)
			write(1, "rrb\n", 4);
	}
}

/*rrr : rra and rrb at the same time.*/

void rrr(head_a *heada, head_a *headb)
{
	rra(heada, 0);
	rrb(headb, 0);
	write(1, "rrr\n", 4);
}