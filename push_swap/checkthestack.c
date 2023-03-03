/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkthestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:37:38 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/03 17:03:33 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkthearg(char *arg)
{
	char	*test;

	test = ft_itoa(ft_atoi(arg));
	if (ft_strcmp(test, arg) != 0)
		return (free(test),0);
	return (free(test),1);
}

int	is_sorted(head_a *a)
{
	a_list	*starta;

	starta = a->first;
	while (starta->next != NULL)
	{
		if (starta->content > starta->next->content
			&& (starta->content != starta->next->content))
		{
			free_list(a -> first, a);
			return (0);
		}
		starta = starta->next;
	}
	return (1);
}

int	check_the_stack(head_a *a)
{
	int	check;

	check = check_doubl(a);
	if (check == 0)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (is_sorted(a) == 1)
		exit(0);
	return (1);
}
