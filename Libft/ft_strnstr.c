/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:34:04 by maria             #+#    #+#             */
/*   Updated: 2022/11/22 22:15:18 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
//14 C does
//not have an implicit conversion from const-qualified pointer types 
//to non-const-qualified ones, so you should add an explicit one, i.e. a cast. 
//Then the warning will go away:
//so 
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	if (len == 1)
		len++;
	if (len == 0)
		return (0);
	while (big[i])
	{
		while (((big[i + j] == little[j]) && little[j] != 0) && j + i < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		j = 0;
		i++;
	}
	return (0);
}
