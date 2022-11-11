/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:53:30 by maria             #+#    #+#             */
/*   Updated: 2022/11/11 19:50:08 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 int ft_toupper(int c)
 {
    if (c >= 97 && c <= 122)
        c -= 32;
    return(c);
 }
// int main(void)
// {
//     unsigned char c;
//     c = 'k';
//     printf("%d\n", toupper(c));
//     printf("%d", ft_toupper(c));
// }
 