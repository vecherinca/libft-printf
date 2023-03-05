/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkthestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:37:38 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 19:12:58 by mklimina         ###   ########.fr       */
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

int	is_sorted(t_head_a *a)
{
	t_a_list	*starta;

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

int	check_the_stack(t_head_a *a, t_head_a *b)
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
