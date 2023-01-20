/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inctructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:10:20 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/20 01:57:49 by mklimina         ###   ########.fr       */
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

// void sb(a_list *head)
// {
// 	int count;
// 	a_list *temp;
// 	int swap;
// 	temp  = head -> next;
// 	count = ft_lstsize(head);
// 	if (count > 1)
// 	{
// 		swap = head-> content;
// 		head -> content = temp -> content;
// 		temp -> content = swap;
// 		// printf("the value of a head updated----> %d\n", head -> content);
// 		// printf("the value of a temp t.e second element ----> %d\n", temp -> content);
// 		write(1, "sb", 2);
// 	}
// }

// /*
// ss : sa and sb at the same time.
// */
// void ss(a_list *head_a, a_list *head_b)
// {
	
// 	// sa(head_a);
// 	// sb(head_b);
// 	// write(1, "ss", 2);
	
// }

/*
pb (push b): Take the first element
at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
void pb(a_list *head_a, a_list *head_b)
{
	int swap;
	a_list *temp;
	temp = head_a;
	swap = head_a -> content;
	head_a = head_a -> next;
	//printf(" swap --- > %d\n", swap);
	//printf("pile a ---- >%d\n",head_a -> content);
	head_b -> content = swap;
	//printf("pile b ---- >  %d",head_b -> content);
	free(temp);
	
}
/*pa (push a): Take the first element
at the top of b and put it at the top of a.
Do nothing if b is empty.
*/
void pa()
{
	
}
