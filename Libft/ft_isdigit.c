/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:40:30 by maria             #+#    #+#             */
/*   Updated: 2022/11/08 17:49:46 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_isdigit(int c)
{
    int i;
    if (c >= 48 && c <= 57)
        return (1);
    else
        return (0);
}

/*int main(void)
{
    char c;
    c = '+';
    printf("%d\n", isdigit(c));
    printf("%d", ft_isdigit(c));
}*/