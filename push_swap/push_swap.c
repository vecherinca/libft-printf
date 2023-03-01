/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/01 15:02:19 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

a_list *create_list(int argc, char **argv)
{
    a_list *head = NULL;
    int i = 1;
    while (i < argc)
    {
        if (checkthearg(argv[i]) == 0)
        {
            write(2, "Error\n", 6);
            exit(0);
        }
        a_list *temp = malloc(sizeof(a_list));
        if (!temp)
            return NULL;
        temp->content = ft_atoi(argv[i]);
        temp->next = NULL;
        ft_lstadd_back(&head, temp);
        i++;
    }
    return head;
}

head_a *define_list_a(int argc, char **argv)
{
    head_a *point = malloc(sizeof(head_a));
    if (!point)
        return NULL;
    point->first = create_list(argc, argv);
    return point;
}

head_a *define_list_b()
{
	head_a *point;
	point = malloc(sizeof(a_list));
	a_list *head = NULL;
	point -> first = head;
	return(point);
}

void pushswap(head_a *a, head_a *b, int argc)
{
	int number;

	number = argc - 1;
	
	if (number == 2)
		sa(a);
	if (number == 3)
		sort3(a);
	if (number == 4)
		sort5(a, b, 4);
	if (number == 5)
		sort5(a, b, 5);
	if (number > 5)
		sort100(a, b);
}

int main(int argc, char **argv)
{
	head_a *a; 
	head_a *b;
	if (argc == 1)
		exit(0);
	a = define_list_a(argc, argv);
	b = define_list_b(); 
	if(!b)
		return(0);
	check_the_stack(a);
	assign_index(a);
	pushswap(a, b, argc);
	// printf("%s********* pile A UPD**********\n", KRED);
	// print_the_list(a);
}

