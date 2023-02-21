/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:02:29 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/21 03:01:07 by maria            ###   ########.fr       */
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

void count_moves_a(a_list *node_a)
{
}

a_list *get_nearest_max(a_list *b_node, head_a *a)
{
	int diff;
	a_list *start_a;
	a_list *first_max;
	start_a = a->first;
	diff = b_node -> index - start_a -> index;
	first_max = start_a;
	//printf("difference ----> %d", diff);
	while (start_a)
	{
		if ((start_a -> index > b_node -> index) && (b_node -> index - start_a -> index > diff))
			first_max = start_a;
		start_a = start_a -> next;
	}
	return(first_max);
}
int number_moves(head_a *a,a_list *b_node, head_a *b, algo_values current)
{
	//count the moves for a/
	//first you need to check the index lol but it's after
	int count;
	int size;
	int total;
	a_list *node;
	a_list *node_a;
	node = b -> first;
	size = ft_lstsize(node);
	//printf("size %d", size);
	count = 0;
	//printf("b_node -> content %d\n", b_node -> content);
	//printf("node -> content %d\n", node -> content);
	while (b_node != node)
	{
		count++;
		node = node -> next;
	}
	if (count < size/2)
		current.rb = count;
	else if(count > size/2)
		current.rrb = size - count + 1;
	
	//printf("current.rrb -- > %d\n", current.rrb);
	//printf("current.rb -- > %d\n", current.rb);
	node_a = get_nearest_max(b_node, a);
	count_moves_a(node_a);
	printf("max_node_a ---> %d\n", node_a -> content);
	total = current.rrb + current.rb;
	return(total);
}
void test_instr(head_a *a,head_a *b)
{
	// here what I want to do is for every node
	// write the number of functions
	a_list *start_a;
	a_list *start_b;
	int numb_moves;
	algo_values current;
	current.rra = 0;
	current.ra = 0;
	current.rrb = 0;
	current.rb = 0;
	
	numb_moves = 0;
	current.node = b -> first;
	start_b = a -> first;
	//now you need to make a function that counts a number of 
	//moves
	//add here node a cause u r gonna send it to another function in order to calculate the sum
	numb_moves = number_moves(a, current.node, b, current);
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
}