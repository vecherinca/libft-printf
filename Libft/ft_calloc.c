/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:17:31 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/11 00:35:12 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	
	char *output;
	if (nmemb == 0 || size == 0)
		return(NULL);
	if (nmemb > 2147483647 || size > 2147483647)
		return(0);
	output = malloc(size * nmemb);
	if (!output)
		return(NULL);
	*output = 0;
	return(output);
		
}