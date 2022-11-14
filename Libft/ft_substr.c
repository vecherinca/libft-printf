/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:53:52 by maria             #+#    #+#             */
/*   Updated: 2022/11/13 23:07:51 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
        char *output;
        unsigned int i;
        unsigned int j;
        unsigned int lenstr;

        i = 0;
        j = 0;
        lenstr = ft_strlen(s);
        output = (char*)calloc(sizeof(char), len + 1);
        if (!output)
            return(NULL);
        output[len] = '\0';
        while (j < len)
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