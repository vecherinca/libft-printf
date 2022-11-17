/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:41:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/17 22:05:50 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strlen(const char *s)
{
    int i;
    i = 0;
    while(s[i])
        i++;
    return(i);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int i;
	unsigned char *source;
	unsigned char *destinaton;
	
	i = 0;
	source = (unsigned char*)src;
	destinaton = (unsigned char *)dest;
	if (destinaton < source)
	{
		while (i < n)
		{
			destinaton[i] = source[i];
			i++;
		}
	
	}
	//why it's working tho?
	else if (destinaton > source) 
	{
		while (n-- > 0)
		{
			destinaton[n] = source[n];
		}
	}
	return(destinaton); 
}
