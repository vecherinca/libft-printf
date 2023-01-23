/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:38:22 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/23 22:09:02 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort3(head_a *a)
{
	a_list *start;
	int one;
	int two;
	int three;

	start = a -> first;
	one = start -> content;
	two = start -> next -> content;
	three = start -> next -> next -> content;
	
	if (one > two && one < three && two < three)
		sa(a);
	if(one > two && one > three && two > three)
	{
		sa(a);
		rra(a);
	}
	if(one > two && one > three && two < three)
		ra(a);
	if(one < two && one < three && two > three)
	{
		sa(a);
		ra(a);
	}
	if(one < two && one > three && two > three)
		rra(a);
}