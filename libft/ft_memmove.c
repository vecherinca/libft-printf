/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:41:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/25 19:31:10 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The memmove() function copies n bytes
from memory area src to memory area dest.
This function treats the overlaps. 
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*source;
	unsigned char	*destinaton;

	i = 0;
	source = (unsigned char *)src;
	destinaton = (unsigned char *)dest;
	if (destinaton < source)
	{
		while (i < n)
		{
			destinaton[i] = source[i];
			i++;
		}
	}
	else if (destinaton > source)
	{
		while (n > 0)
		{
			n--;
			destinaton[n] = source[n];
		}
	}
	return (destinaton);
}
