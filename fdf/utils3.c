/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:41:08 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/25 23:29:42 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	returnzoom(t_lines cnt)
{
	float	value1;
	float	value2;

	value1 = (WINDOW_WIDTH / cnt.ver_i) / 2;
	value2 = (WINDOW_HEIGHT / cnt.hor_j) / 2;
	if (value1 > value2)
		return (value2);
	else
		return (value1);
}

void	freee_tab(t_tab **tab, t_lines cnt)
{
	int	index;

	index = cnt.hor_j;
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
}

t_lines	count_columns(char *name, t_lines cnt)
{
	char	*line;
	int		fd;
	char	**the_line;
	int		i;

	fd = open_fd(name);
	line = get_next_line(fd);
	if (!line)
		exit(56);
	the_line = ft_split(line, 32);
	cnt.ver_i = count_col(the_line);
	i = -1;
	while (the_line[++i + 1])
		continue ;
	if (the_line[i][0] == '\n')
		cnt.ver_i--;
	free(line);
	freee_tab_char(the_line, cnt);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		cnt.hor_j++;
	}
	return (cnt);
}

void	freee_tab_char(char **tab, t_lines cnt)
{
	int	index;

	index = cnt.ver_i;
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
}

int	map_is_flipped(t_data *data)
{
	int	value;

	if (data->theta > 90 && data->theta < 270)
		value = 1;
	else
		value = -1;
	return (value);
}
