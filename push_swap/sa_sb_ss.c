/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:10:20 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 20:10:22 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_head_a *head)
{
	int			count;
	t_a_list	*temp;
	t_a_list	*start;
	int			swap;

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

void	sb(t_head_a *head)
{
	int			count;
	t_a_list	*temp;
	t_a_list	*start;
	int			swap;

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

void	ss(t_head_a *heada, t_head_a *headb)
{
	sa(heada);
	sb(headb);
	write(1, "ss\n", 3);
}
