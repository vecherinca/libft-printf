/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:34:54 by maria             #+#    #+#             */
/*   Updated: 2022/10/27 18:36:55 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
int ft_isalpha(int c)
{
    int i;
    if ((c >= 65 && c<= 90) ||(c >= 97 && c<= 122))
        return(1);
    else
        return(0);
}

int ft_isdigit(int c)
{
    int i;
    if (c >= 48 && c <= 57)
        return (1);
    else
        return (0);
}

int ft_isalnum(int c)
{
    if (ft_isalpha(c) == 1 || ft_isdigit == 1)
        return(1);
    else
        return(0);
}