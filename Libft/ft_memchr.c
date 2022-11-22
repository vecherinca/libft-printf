/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:52:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/22 22:00:09 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)s;
	while (i < n)
	{
		if (string[i] == (char)c)
			return (string + i);
		i++;
	}
	return (NULL);
}
