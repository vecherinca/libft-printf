/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:10:20 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/04 01:52:09 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

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
	}
}

void	ss(head_a *heada, head_a *headb)
{
	sa(heada);
	sb(headb);
}
