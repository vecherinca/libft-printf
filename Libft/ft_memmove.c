/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:41:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/22 22:02:49 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		while (n-- > 0)
		{
			destinaton[n] = source[n];
		}
	}
	return (destinaton);
}
