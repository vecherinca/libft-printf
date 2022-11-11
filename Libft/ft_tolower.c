/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:53:56 by maria             #+#    #+#             */
/*   Updated: 2022/11/11 19:50:13 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 int ft_tolower(int c)
 {
    if (c >= 65 && c <= 90)
        c += 32;
    return(c);
 }
// int main(void)
// {
//     unsigned char c;
//     c = 'k';
//     printf("%d\n", tolower(c));
//     printf("%d", ft_tolower(c));
// }