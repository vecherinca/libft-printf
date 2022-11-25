/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:34:04 by maria             #+#    #+#             */
/*   Updated: 2022/11/25 21:22:09 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Returns a pointer to the first occurrence of str2 in str1, 
or a null pointer if str2 is not part of str1.
*/
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
