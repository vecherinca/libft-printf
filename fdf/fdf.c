/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/03/11 19:23:33 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	*name;
	char	**data;
	t_tab 	**table;
	char 	**tab;
	int 	cnt;
	int		ccnt;
	int		j;
	
	(void) argc;
	name = argv[1];
	cnt = count_lines(name);
	data = malloc(sizeof(char *) * (cnt + 1));
	if(!data)
		return(0);
	data[cnt] = NULL;
	fill_tabtab(data, name);
	int i = 0;
	table = malloc(sizeof(t_tab *) * (cnt + 1));
	table[cnt] = NULL;
	while(data[i]!=NULL)
	{
		j = 0;
		tab = ft_split(data[i], 32);
		ccnt = count_col(tab);
		table[i] = malloc(sizeof(t_tab) * ccnt+1);
		while (tab[j] != NULL)
		{
			table[i][j].x = j;
			table[i][j].y = i;
			table[i][j].z = ft_atoi(tab[j]);
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}	

	print(table, cnt);
}
