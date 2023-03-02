/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:48:03 by maria             #+#    #+#             */
/*   Updated: 2023/03/01 17:48:18 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_nmb(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i = 2;
		n = -n;
	}
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*output;
	int			i;
	long int	num;

	num = (long)n;
	i = count_nmb(num) - 1;
	output = malloc(i + 1 * sizeof(char) + 1);
	if (!output)
		return (NULL);
	output[i + 1] = '\0';
	if (num == 0)
		output[0] = '0';
	if (num < 0)
	{
		output[0] = 45;
		num = -1 * num;
	}
	while (num > 0)
	{
		output[i] = '0' + num % 10;
		num = num / 10;
		i--;
	}
	return (output);
}
