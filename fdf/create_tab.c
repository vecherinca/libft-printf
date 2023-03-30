/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:46:21 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/30 21:51:13 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fillfill(char **data, t_tab **table)
{
	char	**tab;
	int		ccnt;
	int		j;
	int		i;
	i = 0;
	while (data[i] != NULL)
	{
		j = 0;
		tab = ft_split(data[i], 32);
		ccnt = count_col(tab);
		table[i] = malloc(sizeof(t_tab) * ccnt + 1);
		while (tab[j] != NULL)
		{
			table[i][j].x = j;
			table[i][j].y = i;
			table[i][j].z = ft_atoi(tab[j]);
			if (ft_strchr(tab[j], 44) == 0)
				table[i][j].color = -1;
			else
				table[i][j].color = hextoint(ft_strstr(tab[j], "0x"));
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
}

t_tab	**create_ttable(char *name)
{
	char	**data;
	int		cnt;
	t_tab	**table;

	cnt = count_lines(name);
	data = malloc(sizeof(char *) * (cnt + 1));
	if (!data)
		return (0);
	data[cnt] = NULL;
	fill_tabtab(data, name);
	table = malloc(sizeof(t_tab *) * (cnt + 1));
	table[cnt] = NULL;
	fillfill(data, table);
	return (table);
}
