/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:54:15 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/14 20:08:19 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	int len;
	char *output;

	len = ft_strlen(s);
	i = 0;
	if (!s || !f)
		return(0);
	output = malloc(sizeof(char) * (len+1));
	output[len] = 0;
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	return(output);
}