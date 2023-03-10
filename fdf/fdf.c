/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/03/10 22:21:08 by mklimina         ###   ########.fr       */
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

int count_col(char *tab)
{
	int i;
	i = 0;
	while(tab[i]!= '\0')
		i++;
	return(i);
}
int	main(int argc, char **argv)
{
	char	*name;
	char	**data;
	//t_tab 	**table;
	char 	**tab;
	int 	cnt;
	
	(void) argc;
	name = argv[1];
	cnt = count_lines(name);
	data = malloc(sizeof(char *) * (cnt + 1));
	if(!data)
		return(0);
	data[cnt] = NULL;
	fill_tabtab(data, name);
	int i = 0;
	while (data[i] != NULL)
	{
		printf("data--> %s\n",data[i]);
		i++;
	}
	i = 0;
	//table = malloc(sizeof(t_tab*) * (cnt + 1));
	while(data[i]!=NULL)
	{
		int j = 0;
		tab = ft_split(data[i], 32);
		int ccnt;
		ccnt = count_col(tab[j]);
		//here u create malloc
		printf("ccnt --> %d", ccnt);
		while (tab[j]!=NULL)
		{
			printf("%s\n", tab[j]);
			//and here u fill it
			//printf("j ---> %d\n", j);
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
}
