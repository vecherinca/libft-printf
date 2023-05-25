/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:46:21 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/25 23:41:38 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_tab(char *tab)
{
	int	i;
	int	count_digit;
	int	len;

	len = ft_strlen(tab);
	i = 0;
	count_digit = 0;
	while (tab[i])
	{
		if (ft_isdigit(tab[i]))
			count_digit++;
		i++;
	}
	if (count_digit == len)
		return (1);
	else if (ft_strstr(tab, ",0x") != 0)
		return (1);
	return (0);
}

void	init_table(t_tab **table, int i, int j, char **tab)
{
	char	*color;

	while (tab[j] != NULL)
	{
		if (check_tab(tab[j]) == 0)
			exit(98);
		table[i][j].x = j;
		table[i][j].y = i;
		table[i][j].z = ft_atoi(tab[j]);
		if (ft_strchr(tab[j], 44) == 0)
			table[i][j].color = -1;
		else
		{
			color = ft_strstr_v2(tab[j], "0x");
			if (!color_test(color))
				exit(27);
			table[i][j].color = hextoint(ft_strstr(tab[j], "0x"));
		}
		free(tab[j]);
		j++;
	}
}

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
		table[i] = malloc(sizeof(t_tab) * (ccnt + 1));
		init_table(table, i, j, tab);
		free(tab);
		i++;
	}
}

void	freee_tab_char_2(char **tab, t_lines cnt)
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

t_tab	**create_ttable(char *name, t_lines cnt)
{
	char	**data;
	int		ccnt;
	t_tab	**table;

	ccnt = cnt.hor_j;
	data = malloc(sizeof(char *) * (ccnt + 1));
	if (!data)
		return (free(data));
	data[ccnt] = NULL;
	fill_tabtab(data, name);
	table = malloc(sizeof(t_tab *) * (ccnt + 1));
	table[ccnt] = NULL;
	fillfill(data, table);
	freee_tab_char_2(data, cnt);
	return (table);
}
