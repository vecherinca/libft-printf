/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkthestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:37:38 by mklimina          #+#    #+#             */
/*   Updated: 2023/01/23 16:56:14 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
this shit is not handling negative numbers
*/
int checkthearg(char *arg)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(arg);
	if (len == 1 && arg[0] == 45)
		return (0);
	if (properint(arg))
		return(1);
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
		i++;
	}
	return(1);
}

int properint(char *arg)
{
	int len;
	int count;
	int i = 1;
	len = ft_strlen(arg);
	count = 1;
	// if (len == 1 && arg[0] == '-')
	// 	return (0);
	while(arg[i] != '\0')
	{
		if(arg[0] == '-' && ft_isdigit(arg[i]))
			count++;
		i++;
	}
	if (count == len)
		return(1);
	else
		return (0);
}