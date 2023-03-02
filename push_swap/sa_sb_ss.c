/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inctructions_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:10:20 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/01 17:43:28 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(head_a *head)
{
	int		count;
	a_list	*temp;
	a_list	*start;
	int		swap;

	start = head->first;
	temp = start->next;
	count = ft_lstsize(start);
	if (count > 1)
	{
		swap = start->content;
		start->content = temp->content;
		temp->content = swap;
		write(1, "sa\n", 3);
	}
}

void	sb(head_a *head)
{
	int		count;
	a_list	*temp;
	a_list	*start;
	int		swap;

	start = head->first;
	temp = start->next;
	count = ft_lstsize(start);
	if (count > 1)
	{
		swap = start->content;
		start->content = temp->content;
		temp->content = swap;
		write(1, "sb\n", 3);
	}
}

void	ss(head_a *heada, head_a *headb)
{
	sa(heada);
	sb(headb);
	write(1, "ss\n", 3);
}
