/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:23:14 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/24 23:03:13 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*source;
	unsigned char	*destinaton;

	if (!dest && !src)
		return(NULL);
	i = 0;
	source = (unsigned char *)src;
	destinaton = (unsigned char *)dest;
	while (i < n)
	{
		destinaton[i] = source[i];
		i++;
	}
	return (destinaton);
}
