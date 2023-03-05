/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:21:30 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 20:10:03 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag5(t_a_list *temp, t_head_a *a, t_head_a *b)
{
	t_a_list	*min;

	min = find_min(temp);
	pushmin(a, min->content);
	pb(a, b);
	sort3(a);
	pa(a, b);
	pa(a, b);
}

void	sort5(t_head_a *a, t_head_a *b, int flag)
{
	t_a_list	*start;
	t_a_list	*min;
	t_a_list	*temp;

	start = a->first;
	min = find_min(start);
	pushmin(a, min->content);
	if (min->next == NULL)
		temp = a->first;
	else
		temp = min->next;
	pb(a, b);
	if (flag == 5)
		flag5(temp, a, b);
	if (flag == 4)
	{
		sort3(a);
		pa(a, b);
	}
}

t_a_list	*find_min(t_a_list *start)
{
	t_a_list	*min;

	min = start;
	while (start != NULL)
	{
		if (start->content < min->content)
			min = start;
		start = start->next;
	}
	return (min);
}

void	pushmin(t_head_a *a, int min)
{
	t_a_list	*start;
	int			count;
	int			len;

	count = 0;
	start = a->first;
	len = ft_lstsize(start);
	while (start->content != min)
	{
		count++;
		start = start->next;
	}
	start = a->first;
	while (start->content != min)
	{
		if (count <= len / 2)
			ra(a, 1);
		if (count > len / 2)
			rra(a, 1);
		start = a->first;
	}
}
