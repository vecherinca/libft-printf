/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:50:18 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/17 19:43:46 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
so what we are gonna do here
is that we need to revise how to deal with linked lists
the beginning
*/

//this is our linked list node
#include<stdlib.h>
#include<stdio.h>

//can we define it as a list a???

typedef struct a_list
{
	int			content;
	struct a_list	*next;
}a_list;
typedef struct b_list
{
	int			content;
	struct a_list	*next;
}b_list;

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

//now we need to do it a boucle
int main(int argc, char **argv)
{
	a_list *head;
	a_list *tail;
	int i = 1;
	// int x[] = {0,1,2,3,4,5,6,7,8,9,10};
	
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
	while(head != NULL)
	{
		printf(" %d ", head-> content);
        head = head->next;
	}
	
}