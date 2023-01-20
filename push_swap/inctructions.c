/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inctructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:10:20 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/20 22:06:27 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/

void sa(head_a *head)
{
	int count;
	a_list *temp;
	a_list *start;
	int swap;
	start = head -> first;
	temp  = start -> next;
	count = ft_lstsize(start);
	if (count > 1)
	{
		swap = start-> content;
		start -> content = temp -> content;
		temp -> content = swap;
		// printf("the value of a head updated----> %d\n", head -> content);
		// printf("the value of a temp t.e second element ----> %d\n", temp -> content);
		write(1, "sa", 2);
	}
}

/*
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/

void sb(head_a *head)
{
	int count;
	a_list *temp;
	a_list *start;
	int swap;
	start = head -> first;
	temp  = start -> next;
	count = ft_lstsize(start);
	if (count > 1)
	{
		swap = start-> content;
		start -> content = temp -> content;
		temp -> content = swap;
		write(1, "sb", 2);
	}
}

/*
ss : sa and sb at the same time.
check if the count > 1 is nedeed here 
*/
void ss(head_a *heada, head_a *headb)
{
	sa(heada);
	sb(headb);
	write(1, "ss", 2);
}

/*
pb (push b): Take the first element
at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
void pb(head_a *heada, head_a *headb)
{
	a_list *starta;
	starta = heada -> first; // this is our first element
	heada -> first = starta -> next; //here we are pointing to the next 
	headb -> first = starta; // here we assigned something to something lol 
	starta -> next = NULL;
	write(1, "pb", 2);
	
}
/*pa (push a): Take the first element
at the top of b and put it at the top of a.
Do nothing if b is empty.
*/
void pa()
{
	
}
