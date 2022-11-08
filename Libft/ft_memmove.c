/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:41:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/08 23:39:14 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
 #include <string.h>
 
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
	unsigned int len;
	
	i = 0;
	len = ft_strlen(dest);
	//cast the variables to check if they are okay 
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
	if (destinaton > source) 
	{
		while (i < len)
		{
			destinaton[len] = source[len];
			len--;
		}
	}
	return(destinaton); 
}
/*int main()
{
	char dest[] = "Heh";
	printf("address dest %p\n", dest);

	char src[] = "OneTwo";
	printf("address src %p\n", src);
	
	char dest_1[] = "Heh";
	char src_1[] = "OneTwo";
	
	ft_memmove(dest, src, 4);
	
	printf("result of my function -- > %s\n", dest);
	printf("%s\n", "*************************");
	
	memmove(dest_1, src_1, 4);
	printf("result of real function-- > %s", dest_1);
	
}*/