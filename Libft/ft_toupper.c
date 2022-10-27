/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:53:30 by maria             #+#    #+#             */
/*   Updated: 2022/10/27 00:53:32 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
 int ft_toupper(int c)
 {
    if (c >= 97 && c <= 122)
        c -= 32;
    return(c);
 }
int main(void)
{
    unsigned char c;
    c = 'k';
    printf("%d\n", toupper(c));
    printf("%d", ft_toupper(c));
}
 