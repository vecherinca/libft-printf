/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/03/11 17:59:48 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int count_col(char **tab)
{
	int i;
	i = 0;
	while(tab[i]!= NULL)
		i++;
	return(i);
}
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
	table = malloc(sizeof(t_tab) * (cnt + 1));
	table[cnt] = NULL;
	while(data[i]!=NULL)
	{
		j = 0;
		tab = ft_split(data[i], 32);
		ccnt = count_col(tab);
		table[i] = malloc(sizeof(t_tab*) * ccnt+1);
		//printf("tab[i] --> %s\n", tab[j]);
		while (tab[j] != NULL)
		{
			table[i][j].x = j;
			table[i][j].y = i;
			printf("******************\n");
			printf("x ---> %d\n", table[i][j].x);
			printf("y ---> %d\n", table[i][j].y);
			printf("\n");
			printf("******************\n");
			//printf("%s ", tab[j]);
			//and here u fill it
			//printf("j ---> %d\n", j);
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}	

	//print(table, cnt);
    // Print a newline character to separate rows
}
