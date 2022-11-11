/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:58:16 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/11 20:37:52 by mklimina         ###   ########.fr       */
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
		return((unsigned char*)s + len);
	while (s[i])
		{
			if (s[i] == (unsigned char)c)
				return ((unsigned char *)s + i);
			i++;
		}
	return (0);
}