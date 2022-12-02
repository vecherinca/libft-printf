/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:04:01 by mklimina          #+#    #+#             */
/*   Updated: 2022/12/02 21:15:41 by mklimina         ###   ########.fr       */
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
	if (b == 'd' || b == 'i'|| b == 'u')
		return(1);
	if (b == 'x' || b == 'X' || b == 'p')
		return(1);
	return (0);
}

int pourcentage(char c, va_list *args)
{
	char *s;
	int p;
	if (c == 'c')
	{
		p = va_arg(*args, int);
		return(ft_putchar_fd(p));
	}
	if (c == 'd' || c == 'i')
	{
		s = ft_itoa(va_arg(*args, int));
		p = ft_putstr_fd(s);
		free(s);
		return(p);
		//change if to a separate function
			
	}
	if (c == 'u')
	{
		s = ft_itoa_unsign(va_arg(*args, unsigned int));
		p = ft_putstr_fd(s);
		free(s);
		return(p);
		//change it to a sepfunction;
	}
	if (c == 's')
	{
		s = va_arg(*args, char *);
		if (s == NULL)
			return(ft_putstr_fd("(nil)")); 
		return (ft_putstr_fd(s));
	}
	if (c == 'x')
		return(count_hex(va_arg(*args, unsigned int), 'x'));
	if (c == 'X')
		return(count_hex(va_arg(*args, unsigned int), 'X'));
	if (c == 'p')
			return(count_hex(va_arg(*args, unsigned long), 'p'));
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
			count += pourcentage(string[i], &args);
		else if (string[i] != '%')
		{
			write(1, &string[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	//printf("size of my printf ----> %d\n", count);
	return (count);
}
int main()
{
	char c = 66;
	ft_printf("%p\n",&c);
	printf("%p\n", &c);
}