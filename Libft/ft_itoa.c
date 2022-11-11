/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:41:18 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/11 22:27:30 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
// this cute little function counts number of numbers in int
int count_nmb(int n)
{
	int i;

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
char *ft_itoa(int n)
{
	char *output;
	int i;
	int len;
	long int num;
	num = (long)n;

	len = count_nmb(num); // +1 for a '\0'
	i = len - 1;
	output = malloc(len * sizeof(char) + 1);
	if (!output)
		return (NULL);
	output[len] = '\0';
	if (num == 0)
	{
		output[0] = '0';
	}
	if (num < 0)
	{
		output[0] = 45;
		num = -1 * num;
	}
	if (num > 0)
	{
		while (num > 0)
		{
			output[i] = '0' + num % 10;
			num = num / 10;
			i--;
		}
	}
	return (output);
}

// int main ()
// {
//     int i;
//     i = 0;

//     printf("what is inside malloc ----> %s\n", ft_itoa(i));
// }