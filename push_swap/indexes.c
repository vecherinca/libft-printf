/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:59:44 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/28 02:21:02 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(head_a *a)
{
	int temp;
	a_list *start;
	a_list *deux;
	start = a -> first;
	int	i = ft_lstsize(start) - 1;

	while (start != NULL)
	{
			start -> index = i;	
			start = start -> next;
			i--;
	}
	start = a -> first;
	//deux = start -> next;	
	while (start  != NULL)
	{
		//reinit the deux
		deux = start -> next;
		while (deux  != NULL)
		{
			if(start -> content < deux -> content)
			{
				temp = start -> index;
				start -> index = deux -> index;
				deux -> index = temp;
			}
			deux = deux -> next;
		}
		start = start -> next;
	}	
}