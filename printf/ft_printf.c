/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:04:01 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/27 00:32:28 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
// it's not working and I am tired 

void pourcentage(char c, const char *string, ...)
{
	va_list args;
	int p;
	va_start(args, string);
	
	if (c == 'c')
	{
		p = va_arg(args, int);
		write(1, &p, 1);
	}	
	va_end(args);
}
int ft_printf(const char *string, ...)
{
	int i;
	i = 0;
	while (string[i])
	{
		if (string[i] != '%')
			write(1, &string[i], 1);
		else
			pourcentage(string[i + 1], string);
		i++;
	}
	return (0);
}
int main()
{
	// char c = 65;
	ft_printf("Hello here is my char %c", 99);
}