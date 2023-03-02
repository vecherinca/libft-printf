/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:38:22 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/01 20:29:04 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortsort(int one, int two, int three, head_a *a)
{
	if (one > two && one < three && two < three)
		sa(a);
	if (one > two && one > three && two > three)
	{
		sa(a);
		rra(a, 1);
	}
	if (one > two && one > three && two < three)
		ra(a, 1);
	if (one < two && one < three && two > three)
	{
		sa(a);
		ra(a, 1);
	}
	if (one < two && one > three && two > three)
		rra(a, 1);
}

void	sort3(head_a *a)
{
	a_list	*start;
	int		one;
	int		two;
	int		three;

	start = a -> first;
	one = start -> content;
	two = start -> next -> content;
	three = start -> next -> next -> content;
	sortsort(one, two, three, a);
}
