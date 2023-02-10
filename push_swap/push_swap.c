/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/10 23:31:23 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>
/*
what to fix: 1)write standart error
2) if a.out is empty there is an error
3)./a.out 8 7 6 3 1 ---> 13 commands
*/
head_a *define_list_a(int argc, char **argv)
{
	a_list *head;
	head_a *point;
	
	int i = 1;
	head = NULL;
	point = malloc(sizeof(head_a));
	if(!point)
		return(NULL); 
	while (i < argc)
	{
		if (checkthearg(argv[i]) == 0)
		{
				write(1, "Error\n", 6);
				exit(0);
		}
		a_list *temp = malloc(sizeof(a_list));
		if(!temp)
			return(NULL);
		temp -> content = ft_atoi(argv[i]);
		temp -> next = NULL;
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
void pushswap(head_a *a, head_a *b, int argc)
{
	int number;

	number = argc - 1;
	
	if (number == 2)
		sa(a);
	if (number == 3)
		sort3(a);
	if (number == 5)
		sort5(a, b);
	if (number > 5)
		sort100(a, b);
}
/*
./a.out 5 1000 8 0 -1
for this case it's giving 13 fix that
*/
int main(int argc, char **argv)
{
	head_a *a; 
	int check;
	//int check_srt;
	head_a *b;
	a = define_list_a(argc, argv);
	b = define_list_b();

	if(!b)
		return(0);
	check = check_doubl(a);
	if (check == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	assign_index(a);
	// printf("\n");
	// printf("%s********* pile A **********\n", KCYN);	
	// print_the_list(a);
	//printf("%s****** content vs indexes ********\n", KRED);
	///print_side_by_side(a);
	
	// //a_list *start = a -> first;
	// // while (start -> next != NULL)
	// // {
	// // 	//printf("index --- > %d\n", start -> content);
	// // 	start = start -> next;
	// // }
	// printf("%s****** COMMANDS ********\n", KGRN);
	pushswap(a, b, argc);
	printf("%s********* pile A **********\n", KCYN);
	print_the_list(a);
	printf("%s********* pile B **********\n", KRED);
	print_the_list(b);
	// printf("%s****** END COMMANDS ********\n", KGRN);
	// printf("%s********* pile A UPD**********\n", KRED);
	// print_the_list(a);
	// printf("%s****** PILE B ********\n", KYEL);
	// print_the_list(b);
}

