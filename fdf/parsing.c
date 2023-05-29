/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:01:34 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/29 22:11:10 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_value(char *hexa, char c)
{
	int	i;

	i = 0;
	while (hexa[i] != '\0')
	{
		if (hexa[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	color_test(char *color)
{
	char	*hexa;
	int		i;

	i = 2;
	hexa = "ABCDEFabcdef1234567890\n";
	printf("color --> %s\n", color);
	if (ft_strlen(color) == 2 || ft_strlen(color) > 9)
		return (0);
	while (color[i] != '\0')
	{
		if (check_value(hexa, color[i]))
			return (0);
		i++;
	}
	return (1);
}

int	open_fd(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		exit(0);
	return (fd);
}
