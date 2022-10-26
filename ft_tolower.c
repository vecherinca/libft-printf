/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:53:56 by maria             #+#    #+#             */
/*   Updated: 2022/10/27 00:55:24 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
 int ft_tolower(int c)
 {
    if (c >= 65 && c <= 90)
        c += 32;
    return(c);
 }
int main(void)
{
    unsigned char c;
    c = 'k';
    printf("%d\n", tolower(c));
    printf("%d", ft_tolower(c));
}