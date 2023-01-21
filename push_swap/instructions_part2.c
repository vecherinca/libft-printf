/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:52:53 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/21 22:21:11 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.*/
void ra(head_a *heada)
{
	a_list *starta;
	a_list *finish;
	a_list *prev;
		
	starta = heada -> first;
	prev = findsecondlastnode(starta);
	finish = ft_lstlast(starta);
	heada -> first = finish;
	prev -> next = NULL;
	finish -> next = starta;
	write(1, "ra\n", 3);
	
}
/*rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.*/
void rb(head_a *headb)
{
	a_list *startb;
	a_list *finish;
	a_list *prev;
		
	startb = headb -> first;
	prev = findsecondlastnode(startb);
	finish = ft_lstlast(startb);
	headb -> first = finish;
	prev -> next = NULL;
	finish -> next = startb;
	write(1, "rb\n", 3);
}
/**rr : ra and rb at the same time.**/
void rr()
{
	
}
/**rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.**/
void rra()
{
	
}

/**rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first on**/
void rrb()
{
	
}