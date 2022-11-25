/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:52:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/25 18:43:07 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The memchr() function scans the initial n bytes of the memory
area pointed to by s for the first instance of c.  Both c and the
bytes of the memory area pointed to by s are interpreted as unsigned char.

The memchr() function return a pointer to the
matching byte or NULL if the character does
not occur in the given memory area.
*/
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
