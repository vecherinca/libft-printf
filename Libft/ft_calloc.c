/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:17:31 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/22 21:26:24 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{	
	void	*output;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > 65535 || size > 65535)
		return (0);
	output = (void *)malloc(size * nmemb);
	if (!output)
		return (NULL);
	ft_bzero(output, nmemb * size);
	return (output);
}
