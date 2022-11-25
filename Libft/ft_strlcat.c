/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:22:38 by maria             #+#    #+#             */
/*   Updated: 2022/11/25 22:51:05 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The strlcat() function concatenate strings. It's designed to be safer
and more consistent than strncat().
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int				dest_len;
	unsigned int				src_len;
	unsigned int				i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize == 0 || dstsize <= dest_len)
		return (dstsize + src_len);
	while (src[i] && i < dstsize - dest_len - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
