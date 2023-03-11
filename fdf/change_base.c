/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:09:37 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/11 22:19:28 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*to_up(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	powerof(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * (powerof(nb, power - 1)));
}

int hextoint(char *hex)
{
	int	i;
	int	x;
	int y;
	int number;
	number = 0;
	y = 0;
	i = len(hex) - 1;
	hex = to_up(hex);
	printf("hex ---> %s\n", hex);
	while (i >= 0)
	{
		printf("x\n");
		if (hex[i] >= '0' && hex[i] <= '9')
			x = hex[i] - '0';
		else
			x = hex[i] - 'A' + 10;
		number = number + x * powerof(16, y);
		printf("number middle ---> %d\n", number);
		i--;
		y++;
	}
	printf("number ---> %d\n", number);
	printf("******************\n");
	return (number);
}

// int main()
// {	
// 	char hex[] = "810202";
// 	printf("NUMBER ----> %d", hextoint(hex));
// }