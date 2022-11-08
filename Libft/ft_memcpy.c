/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:23:14 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/08 18:35:16 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;
	unsigned char *source;
	unsigned char *destinaton;
	
	i = 0;
	//cast the variables 
	source = (unsigned char*)src;
	destinaton = (unsigned char *)dest;
	
	while (i < n)
	{
		destinaton[i] = source[i];
		i++;
	}
	return(destinaton);
}