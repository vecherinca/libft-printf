/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/22 22:44:49 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include<stdlib.h>
#include<stdio.h>


head_a *define_list_a(int argc, char **argv)
{
	a_list *head;
	head_a *point;
	
	//int check;

	int i = 1;
	head = NULL;
	point = malloc(sizeof(head_a));
	while (i < argc)
	{
		if (checkthearg(argv[i]) == 0)
		{
				write(1, "Error\n", 6);
				exit(0);
		}
		a_list *temp = malloc(sizeof(a_list));
		temp -> content = ft_atoi(argv[i]);
		
		ft_lstadd_back(&head, temp);
		i++;
	}
	point -> first = head;
	return (point);
}
head_a *define_list_b()
{
	head_a *point;
	point = malloc(sizeof(a_list));
	a_list *head  = NULL;
	point -> first = head;
	return(point);
}

void print_the_list(head_a *head)
{
	a_list *start;
	start = head -> first;
	while(start != NULL)
	{	

		printf("%d\n", start -> content);
        start = start -> next;
	}
}
int main(int argc, char **argv)
{
	head_a *a; 
	int check;
	//int check_srt;

	//head_a *b;
	//b = define_list_b();
	a = define_list_a(argc, argv);	
	check = check_doubl(a);
	if (check == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	printf("%spile A\n", KBLU);	
	printf("******\n");
	print_the_list(a);
	
}

