/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:47:56 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/24 23:05:59 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*output;

	if (!s1 || !s2)
		return(NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	output = malloc(sizeof(char) * len);
	if(!output)
			return(NULL);
	output[len - 1] = '\0';
	if (!output)
		return (NULL);
	output[0] = 0;
	while (s1[i] != '\0')
	{
		output[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		output[i] = s2[j];
		i++;
		j++;
	}
	return (output);
}
