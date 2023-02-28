/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:11:19 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/28 23:43:53 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void print_index(head_a *head)
{
	a_list *start;
	start = head -> first;
	while(start != NULL)
	{	
		printf("%d\n", start -> index);
        start = start -> next;
	}
}

void print_side_by_side(head_a *head)
{
    a_list *start = head->first;

	 printf("INDEX\t\tCONTENT\n");
    while(start != NULL)
    {   
        printf("%d\t\t%d\n", start->index, start->content);
        start = start->next;
    }
}