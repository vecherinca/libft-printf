/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:58:11 by maria             #+#    #+#             */
/*   Updated: 2022/10/26 21:17:29 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
    if (str[i] == '+')
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
    char t[] = " +1234";
    printf("%d", ft_atoi(t));
}*/