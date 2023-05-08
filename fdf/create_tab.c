/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:46:21 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/08 21:03:28 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fillfill(char **data, t_tab **table, t_lines cnt)
{
	char	**tab;
	int		ccnt;
	int		j;
	int		i;
	(void) cnt;
	i = 0;
	while (data[i] != NULL)
	{
		j = 0;
		tab = ft_split(data[i], 32);
		ccnt = count_col(tab);
		//printf("data[%d] ---> %s\n",i, data[i]);
		table[i] = malloc(sizeof(t_tab) * (ccnt + 1));
		while (tab[j] != NULL)
		{
			table[i][j].x = j;
			table[i][j].y = i;
			table[i][j].z = ft_atoi(tab[j]);
			//printf("%s tab(j) %s\n", KGRN,  tab[j]);
			
			if (ft_strchr(tab[j], 44) == 0)
				table[i][j].color = -1;
			else
				table[i][j].color = hextoint(ft_strstr(tab[j], "0x"));
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
		printf("i ---> %d\n", i);
	}
}

t_tab	**create_ttable(char *name, t_lines cnt)
{
	char	**data;
	int		ccnt;
	t_tab	**table;
	ccnt = cnt.hor_j;
	//printf("number of lines --> %d", cnt);
	data = malloc(sizeof(char *) * (ccnt + 1));
	if (!data)
		return (0);
	data[ccnt] = NULL;
	fill_tabtab(data, name);
	//printf("data[3] ----> %s\n", data[2]);
	table = malloc(sizeof(t_tab *) * (ccnt + 1));
	table[ccnt] = NULL;
	fillfill(data, table, cnt);
	return (table);
}
