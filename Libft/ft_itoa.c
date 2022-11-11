/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:41:18 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/11 18:22:56 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// this cute little function counts number of numbers in int
int count_nmb(int n)
{
	int i;

	i = 1;
	while (n / 10)
	{	
		i++;
		n = n/10;
	}
	return (i);
		
}
char *ft_itoa(int n)
{
	char *output;
	int i;
	int len;

	i = 0;
	len = count_nmb(n) + 1; // +1 for a '\0'
	output = malloc(len * sizeof(char));
	if (!output)
		return(NULL);
	output[len - 1] = '\0';
	if (n > 0)
	{
		output[i] = '0' + n/10;
		
	}
	
}
