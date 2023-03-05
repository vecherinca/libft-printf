/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numberofmoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:35:10 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 20:09:13 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_algo_values	count_moves_a(t_a_list *node_a, t_head_a *a,
		t_algo_values current)
{
	int			count;
	int			size;
	t_a_list	*starta;

	current.ra = 0;
	current.rra = 0;
	starta = a->first;
	size = ft_lstsize(starta);
	count = 0;
	while (node_a != starta)
	{
		count++;
		starta = starta->next;
	}
	if (count <= size / 2)
		current.ra = count;
	else if (count > size / 2)
		current.rra = size - count;
	return (current);
}

t_a_list	*get_nearest_max(t_a_list *b_node, t_head_a *a)
{
	t_a_list	*start_a;
	t_a_list	*first_max;

	start_a = a->first;
	first_max = find_max_nnode(start_a);
	while (start_a != NULL)
	{
		if ((start_a->index > b_node->index)
			&& (start_a->index < first_max->index))
			first_max = start_a;
		start_a = start_a->next;
	}
	return (first_max);
}

t_algo_values	number_moves(t_head_a *a, t_a_list *b_node, t_head_a *b,
		t_algo_values cur)
{
	int			count;
	int			size;
	t_a_list	*node;
	t_a_list	*node_a;

	cur.rb = 0;
	cur.rrb = 0;
	node = b->first;
	size = ft_lstsize(node);
	count = 0;
	while (b_node != node)
	{
		count++;
		node = node->next;
	}
	if (count <= size / 2)
		cur.rb = count;
	else if (count > size / 2)
		cur.rrb = size - count;
	node_a = get_nearest_max(b_node, a);
	cur = count_moves_a(node_a, a, cur);
	return (cur);
}

int	calc_instructions(t_algo_values current, t_algo_values next_node)
{
	int	total_current;
	int	nnext_node;

	total_current = current.rra + current.rrb + current.rb + current.ra;
	nnext_node = next_node.rra + next_node.rrb + next_node.rb + next_node.ra;
	if (nnext_node < total_current)
		return (1);
	else
		return (0);
}
