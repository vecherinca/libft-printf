/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkthestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:37:38 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/03 18:43:12 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkthearg(char *arg)
{
	char	*test;

	test = ft_itoa(ft_atoi(arg));
	if (ft_strcmp(test, arg) != 0)
		return (free(test), 0);
	return (free(test), 1);
}

int	is_sorted(head_a *a)
{
	a_list	*starta;

	starta = a->first;
	while (starta->next != NULL)
	{
		if (starta->content > starta->next->content
			&& (starta->content != starta->next->content))
			return (0);
		starta = starta->next;
	}
	return (1);
}

int	check_the_stack(head_a *a, head_a *b)
{
	int	check;

	check = check_doubl(a);
	if (check == 0)
	{
		write(2, "Error\n", 6);
		free_list(a-> first, a);
		free_list(b-> first, b);
		exit(0);
	}
	if (is_sorted(a) == 1)
	{
		free_list(a-> first, a);
		free_list(b-> first, b);
		exit(0);
	}
	return (1);
}
