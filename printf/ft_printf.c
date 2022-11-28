/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:04:01 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/28 22:45:50 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
# include <stdio.h>
// it's not working and I am tired 

int rightletter(char b)
{
	if (b == 'c' || b == 's')
		return(1);
	if (b == 'd' || b == 'i')
		return(1);
	return (0);
}

int pourcentage(char c, va_list args)
{
	//int p;
	char *s;
	int p;
	if (c == 'c')
	{
		p = va_arg(args, int);
		return(ft_putchar_fd(p));
	}
	if (c == 'd' || c == 'i')
	{
		return(ft_putnbr_fd(va_arg(args, int)));
	}
	if (c == 's')
	{
		s = va_arg(args, char *);
		return (ft_putstr_fd(s));
	}
	return(0);
		
}
int ft_printf(const char *string, ...)
{
	int i;
	va_list args;
	int count;
	
	i = 0;
	count = 0;
	
	va_start(args, string);
	while (string[i])
	{
		if (rightletter(string[i]) && string[i - 1] == '%')
			count += pourcentage(string[i], args);
		else if (string[i] != '%')
		{
			write(1, &string[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	printf("size ----> %d\n", count);
	return (count);
}
int main()
{
	// // char c = 65;
	printf("****************** \n");
	ft_printf("Hello here are my chars ----> %c, %c ehehhehehhe\n", 104, 105);
	// ft_printf("\n");
	ft_printf("And this is a string -----> %s\n", "Onetwoii");
	ft_printf("And this is a decimal hehe -----> %d, %c, %d\n", 128858, 124, 66);
	// ft_printf("\n");
	// // ft_printf("And this is an integer somehow it's the same as decimal-----> %i\n", 12345054);
	// // ft_printf("\n");
	printf("****************** \n");
}