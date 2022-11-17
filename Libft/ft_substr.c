/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:50:41 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/17 22:15:14 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
        char *output;
		size_t lenstr;
		lenstr = ft_strlen(s);
        size_t j;

        j = 0;
		// if (!s)
		// 	return (0);
		if (start > lenstr)
			return(ft_strdup(""));
		if (len >= lenstr)
			output = (char*)ft_calloc(lenstr - start + 1,sizeof(char));
		else
        	output = (char*)ft_calloc(len + 1, sizeof(char));
        if (!output)
            return(NULL);
        while (j < len && s[start]!='\0')
        {
            output[j] = s[start]; 
            start++;
            j++;      
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