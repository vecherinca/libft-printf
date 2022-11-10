/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:52:08 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/10 20:20:47 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
 void *ft_memchr(const void *s, int c, size_t n)
 {
		char *string;
		int i;
		
		i = 0;
		string = (char *)s;
		
		
		while (i < n)
		{
			if (string[i] == c)
				return(string+i);
			i++;
		}
		return(NULL);
 }
int main(int argc, const char * argv[])
{
    char search[] = "TechOnTheNet";
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char s_1[] = {0, 1, 2 ,3 ,4 ,5};
    char *ptr;
	char *ptr_1;

	printf("%s", "************Real function**************\n");
    /* Return a pointer to the first 'N' within the search string */
    ptr = (char*)memchr(s, 2 + 256, 3);

    /* If 'N' was found, print its location (This should produce "10") */
    if (ptr != NULL) printf("Found 'N' at position %ld.\n", 1+(ptr-s));
    else printf("'N' was not found.\n");

	printf("%s\n", " ");
	printf("%s", "************My function**************\n");
	
	ptr_1 = (char*)ft_memchr(s_1, 2 + 256, 3);
    if (ptr_1 != NULL) printf("Found 'N' at position %ld.\n", 1+(ptr_1-s_1));
    else printf("'N' was not found.\n");
}