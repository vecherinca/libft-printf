/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 21:04:01 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/26 21:04:06 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <unistd.h>
#include <stdarg.h>
int ft_printf(const char *string, ...) //we don't have a var here so how do I call it lol
{
	va_list args; //can we use it hehe??? 
	va_start(args, string);
	int i;
	char c;
	i = 0;
	while (string[i])
	{	
		if (string[i] == '%' && string[i + 1] != '%')
		{
			c = va_arg(args, int);	
			write(1, &c, 1);
			i = i + 2;
		}
		write(1, &string[i], 1);
		i++;
		va_end(args);
	}
	return(0);
}
int main()
{
	char c = 65;
	ft_printf("Hello here is my char %c, %c", c, 66, 77);
}