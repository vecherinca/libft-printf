/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:27:27 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/28 23:54:42 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
Outputs the integer ’n’ to the given file
descriptor.
*/
void    print(int nb, int fd)
{
    int    number;
    
    number = 48 + nb;
    write(fd, &number, 1);
}
int    count_nmb(int n)
{
    int    i;

    i = 1;
    
    while (n / 10)
    {
        i++;
        n = n / 10;
    }
    return (i);
}

int  ft_putnbr_un(int n)
{
    int count;
    count = count_nmb(n);
    
    if (n < 10 && n >= 0)
    {
        print(n, 1);
        count = 1;
    }
    if (n > 9)
    {
        ft_putnbr_fd(n / 10);
        ft_putnbr_fd(n % 10);
    }
    return(count);
}
