/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:50:41 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/13 21:00:31 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	unsigned int l;
	char *output;
	l = ft_strlen(s);
	if(len > l)
		return(NULL);
	output = (char *)malloc(len+1*sizeof(char));
	if (!output)
		return(NULL);
	i = 0;
	ft_bzero(output, len);
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