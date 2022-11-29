/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:23:03 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/29 18:45:58 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
Outputs the string ’s’ to the given file
descriptor.
*/
unsigned 	int	ft_putstr_unsign(char *s)
{
	unsigned int	i;
	unsigned int count;
	count = 0;
	if (!s)
		return(0);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return(count);
}
