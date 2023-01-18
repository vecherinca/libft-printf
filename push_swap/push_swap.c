/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/18 23:04:29 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include<stdlib.h>
#include<stdio.h>

a_list *define_list_a(int argc, char **argv)
{
	a_list *head;
	a_list *tail;
	int i = 1;
	
	head = NULL;
	tail = NULL;

	while (i < argc)
	{
		a_list *temp = malloc(sizeof(a_list));
		temp -> content = ft_atoi(argv[i]);
		temp -> next = NULL;
		if (tail == NULL)
		{
			head = temp;
			tail = temp;
		}
		else 
		{
			tail -> next = temp;
			tail = temp;
		}
		i++;
	}
	return (head);
}
a_list *define_list_b()
{
	a_list *head;
	head = NULL;
	return(head);
}

int main(int argc, char **argv)
{
	a_list *a;
	a_list *b;
	
	b = define_list_b();
	a = define_list_a(argc, argv);
	
	printf("pile A\n");	
	printf("******\n");
	// while(a != NULL)
	// {
	// 	printf("%d\n", a -> content);
    //     a = a -> next;
	// }
	printf("-----------------------------\n");
	printf("pile B\n");	
	printf("******\n");
	while(b != NULL)
	{
		printf("%d\n", b -> content);
        b = b -> next;
	}

	printf("the size of an **A** --->");
	sa(a);
}

