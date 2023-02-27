/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:29 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/27 01:20:14 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushto_median(a_list *start, head_a *b, head_a *a, int median)
{
	if (start -> index <= median)
	{
		pb(a, b);
		rb(b, 1);
	}
	else
		pb(a, b);
}

void presort(int median, head_a *b, head_a *a)
{
	int maximum;
	a_list *start;
	start = a->first;
	//i think it's -1 for sure but check lol
	maximum = ft_lstsize(start) - 1;
	while (start -> next != NULL)
	{
		if (start -> index != maximum)
			pushto_median(start, b, a, median);
		else
			rra(a, 1);
		start = a->first;
	}
}
//je sais pas si c marche comme je veux
algo_values count_moves_a(a_list *node_a, head_a *a, algo_values current)
{
	int count;
	int size;
	a_list *starta;

	current.ra = 0;
	current.rra = 0;
	
	starta = a -> first;
	size = ft_lstsize(starta);
	//printf("SIZE//2 %d\n", size/2);
	count = 0;
	//printf("First node of A --> %d\n", starta -> index);
	while (node_a != starta)
	{
		count++;
		starta = starta -> next;
	}
	if (count <= size/2)
		current.ra = count;
	else if(count > size/2)
		current.rra = size - count;
	return(current);
}
a_list *find_max_nnode(a_list *start)
{
	a_list *max;
	max = start;
	while (start != NULL)
	{
		if (start -> content > max -> content)
			max = start;
		start = start -> next;
	}
	return(max);
}
a_list *get_nearest_max(a_list *b_node, head_a *a)
{
	int diff;
	a_list *start_a;
	a_list *first_max;
	int max;

	start_a = a->first;
	//max = find_max(start_a);
	first_max = find_max_nnode(start_a);
	//printf
	while (start_a != NULL)
	{
		if ((start_a -> index > b_node -> index) && (start_a -> index < first_max -> index))
			first_max = start_a;
		start_a = start_a -> next;
	}
	return(first_max);
}
algo_values number_moves(head_a *a,a_list *b_node, head_a *b, algo_values current)
{
	// b_node is initialized value
	int count;
	int size;
	//int total;
	a_list *node; // it's a random node
	a_list *node_a;
	
	current.rb = 0;
	current.rrb = 0;
	
	node = b -> first; 
	size = ft_lstsize(node);
	count = 0;
	while (b_node != node)
	{
		count++;
		node = node -> next;
	}
	if (count <= size/2)
		current.rb = count;
	else if(count > size/2)
		current.rrb = size - count;
	
	node_a = get_nearest_max(b_node, a);
	current = count_moves_a(node_a, a, current);
	//printf("THE CLOSEST MAX ---> %d\n", node_a -> index);
	// printf("THE ---> %d\n", node_a -> index);
	return(current);
}

int calc_instructions(algo_values current, algo_values next_node)
{
	int total_current;
	int total_next_node;

	total_current = current.rra + current.rrb + current.rb + current.ra;
	total_next_node = next_node.rra + next_node.rrb + next_node.rb +next_node.ra;

	if (total_next_node < total_current)
		return(1);
	else
		return(0);
}
void test_instr(head_a *a,head_a *b)
{
	// here what I want to do is for every node
	// write the number of functions
	a_list *start_a;
	a_list *start_b;
	int numb_moves;
	algo_values current;
	algo_values next_node;

	current.node = b -> first;
	start_b = b -> first;
	while (start_b)
	{
		current = number_moves(a, start_b, b, current);
		while (start_b != NULL)
		{
			next_node = number_moves(a, start_b, b, next_node);
			if (calc_instructions(current, next_node) == 1)
				current = next_node;
			start_b = start_b -> next;
		}
		printf("******************* %s\n", KMAG);
		printf("LIST A\n");
		print_index(a);
		printf("******************* %s\n", KRED);
		printf("LIST B\n");
		print_index(b);
		printf("******************* %s\n", KBLU);
		printf("EACH ITERATION FOR CURRENT NODE\n");
		printf("current.rrb -- > %d\n", current.rrb);
		printf("current.rb -- > %d\n", current.rb);
		printf("current.rra -- > %d\n", current.rra);
		printf("current.ra -- > %d\n", current.ra);
		movefastest(current, a, b);
		pa(a,b);
		start_b = b -> first;
	}
	// 
	//printf("Number of moves --> %d\n", numb_moves);
	//printf("current.node ----> %d\n", current.node -> content);
	// also here you write a loop while 
	// where you compare lol
}

void sort100(head_a *a,head_a *b)
{
	int median;
	a_list *start;
	start = a -> first;
	median = ft_lstsize(start)/2;
	presort(median, b, a);
	test_instr(a, b);
	printf("LIST A\n");
	print_index(a);
	// printf("LIST B\n");
	// print_index(b);
}