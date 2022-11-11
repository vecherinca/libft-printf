/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:10:59 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/11 19:53:21 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;
    i = 0;
    sign = 1;
    result = 0;

    while (str[i] == 32 || (str[i] >= 9 && str[i]<= 13)) 
    {
       i++;
    }
    if (str[i] == '-')
    {
        sign = -1 * sign; 
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0'; 
        i++;
    }
    return(result * sign);
}

/*int main(void)
{
    char t[] = " +-";
    printf("%d", ft_atoi(t));
}*/