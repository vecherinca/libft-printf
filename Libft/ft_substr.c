/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:50:41 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/13 19:14:56 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	unsigned int j;
	unsigned l;
	char *output;
	l = ft_strlen(s);
	j = 0;
	i = 0;
	if (len > l)
		return(NULL);
	if (start > l)
		return(0);
	output = malloc(sizeof(char) * (len + 1));
	if(!output)
		return(0);
	output[len] = '\0';
	//moving to the start positions
	while (i != start)
		i++;
	while (len > 0)
	{
		output[j] = s[i];
		i++;
		j++;
		len--;
	}
	 return(0);
}
// int main()
// {
//   char s[] = "tripouille";
//   int start = 0;
//   int len = 42000;
//   printf("%s", ft_substr(s, start, len));
// }