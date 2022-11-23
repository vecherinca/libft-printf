/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:17:31 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/23 22:05:48 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{	
	void	*output;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb * size < size)
		return (0);
	output = (void *)malloc(size * nmemb);
	if (!output)
		return (NULL);
	ft_bzero(output, nmemb * size);
	return (output);
}
