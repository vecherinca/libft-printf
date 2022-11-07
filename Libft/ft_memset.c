/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:24:58 by maria             #+#    #+#             */
/*   Updated: 2022/11/07 23:52:34 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void *ft_memset(void *s, int c, size_t n)
{
    unsigned int i;    
    i = 0;
    while(i < n)
    {
        ((char *)s)[i] = c;
        i++;
    } 
}
/*int main()
{   
    int c = 45;
    char str[] = "ddddddddddd";
    ft_memset(str, c, 6);
    printf("%s", str);
}*/