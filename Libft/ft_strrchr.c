/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:27:43 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/11 21:15:14 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char *ft_strrchr(const char *s, int c)
{

	int len;

	len = ft_strlen(s);
	if (c == 0)
		return((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
		len--;
	}
	return (0);
}

// int main()
// {
// 	char s[] = "tripouille";
// 	printf("this thing should print a full string ---> %s\n",ft_strrchr(s, 't'));
// }