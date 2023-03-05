/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:10:20 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 19:12:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void	sa(t_head_a *head)
{
	int		count;
	t_a_list	*temp;
	t_a_list	*start;
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

void	sb(t_head_a *head)
{
	int		count;
	t_a_list	*temp;
	t_a_list	*start;
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

void	ss(t_head_a *heada, t_head_a *headb)
{
	sa(heada);
	sb(headb);
}
