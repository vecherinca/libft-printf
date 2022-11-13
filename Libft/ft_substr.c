/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:50:41 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/13 20:37:08 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	unsigned int j;
	char *output;
	output = malloc(sizeof(char) * (len));
	if (!output)
		return(NULL);
	i = 0;
	j = 0;
	while(len > 0)
	{
		output[i] = s[start];
		i++;
		start++;
		len--;
	}
	return(output);
}
// int main()
// {
//   char s[] = "tripouille";
//   int start = 0;
//   int len = 42000;
//   printf("%s", ft_substr(s, start, len));
// }