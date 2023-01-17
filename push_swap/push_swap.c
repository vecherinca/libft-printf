/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/17 19:46:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include<stdlib.h>
#include<stdio.h>

//can we define it as a list a???

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1 * sign;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void push_swap()
{
	
}
int main(int argc, char **argv)
{
	a_list *head;
	a_list *tail;
	int i = 1;
	
	head = NULL;
	tail = NULL;

	while (i < argc)
	{
		a_list *temp = malloc(sizeof(a_list)); //this size of is triggering me as hell
		temp -> content = ft_atoi(argv[i]);
		temp -> next = NULL;

		//here we say that if it's our first iteration we assign head and
		//tail to the temp cause it's like the literally the only thing we have lol			
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
	printf("pile A lol\n");	
	printf("******\n");
	while(head != NULL)
	{
		printf("%d\n", head-> content);
        head = head->next;
	}
	
}

