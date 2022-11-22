/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:50:41 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/22 22:33:36 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	lenstr;
	size_t	j;

	lenstr = ft_strlen(s);
	j = 0;
	if (start > lenstr)
		return (ft_strdup(""));
	if (len >= lenstr)
		output = (char *)ft_calloc(lenstr - start + 1, sizeof(char));
	else
		output = (char *)ft_calloc(len + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (j < len && s[start] != '\0')
	{
		output[j] = s[start];
		start++;
		j++;
	}
	return (output);
}
