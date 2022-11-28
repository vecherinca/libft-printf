/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:04:01 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/28 18:58:47 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
// it's not working and I am tired 

int rightletter(char b)
{
	if (b == 'c')
		return(1);
	if (b == 'd')
		return(1);
	return (0);
}

void pourcentage(char c, va_list args)
{
	int p;
	p = va_arg(args, int);
	if (c == 'c')
	{
		write(1, &p, 1);
	}
	if (c == 'd')
	{
		ft_putnbr_fd(p, 1);
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
	ft_printf("Hello here is my char %d, %c, %c, %d", 104, 105, 106, 104);
}