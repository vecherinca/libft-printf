/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:04:01 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/27 15:39:55 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
// it's not working and I am tired 

int rightletter(char c)
{
	if (c = 'c')
		return(1);
}
void pourcentage(char c, va_list args)
{
	int p;
	if (c == 'c')
	{
		p = va_arg(args, int);
		write(1, &p, 1);
	}	
}
int ft_printf(const char *string, ...)
{
	int i;
	i = 0;
	va_list args;
	va_start(args, string);
	while (string[i])
	{
		if (rightletter(string[i]) && string[i - 1] == '%')
			pourcentage(string[i], args);
		else if (string[i] != '%')
			write(1, &string[i], 1);
		i++;
	}
	return (0);
}
int main()
{
	// char c = 65;
	ft_printf("Hello here is my char %c", 104);
}