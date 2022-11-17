/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:58:16 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/17 22:10:09 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_strchr(const char *s, int c)
{
	int	i;
	int len;
	len = ft_strlen(s);
	i = 0;
	if (c == 0)
		return((char*)s + len);
	while (s[i])
		{
			if (s[i] == (char)c)
				return ((char *)s + i);
			i++;
		}
	return (0);
}