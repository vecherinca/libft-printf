/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:44:03 by maria             #+#    #+#             */
/*   Updated: 2023/03/11 19:23:42 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print(t_tab **table, int cnt)
{
	int i;
	int j;
	i = 0;
	while (i < cnt) 
	{
		j = 0;
    	while (j < cnt) 
		{
        // Print the x and y values for the current element
       		printf("%s(%d, %d, %d) ", KGRN, table[i][j].x, table[i][j].y, table[i][j].z);
       		j++;
		}
    	printf("\n");
    	i++;
    }
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1 * sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int count_col(char **tab)
{
	int i;
	i = 0;
	while(tab[i]!= NULL)
		i++;
	return(i);
}

int count_lines(char *name)
{
	int 	fd;
	char 	buffer[1];
	int		bytes;
	int		cnt;	
	
	cnt = -1;
	fd = open(name, O_RDONLY);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buffer, 1);
		if(buffer[0] == '\n')
			cnt++;
	}
	return(cnt);
	
}

void fill_tabtab(char **data, char *name)
{
	int fd;
	int	i;

	i = 0;
	fd = open(name, O_RDONLY);
	while (1)
	{
		data[i] = get_next_line(fd);
		if(data[i] == NULL)
			break ;
		i++;
	}
}
