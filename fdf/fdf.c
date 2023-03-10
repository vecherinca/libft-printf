/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/03/10 04:38:14 by maria            ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	char	*name;
	int 	fd;
	char	**data;
	int 	cnt;
	int		i;
	(void) argc;
	// (void) data;
	name = argv[1];
	i = 0;
	cnt = count_lines(name);
	data = malloc(sizeof(char *) * (cnt + 1));
	if(!data)
		return(0);
	data[cnt] = NULL;
	fd = open(name, O_RDONLY);
	while (1)
	{
		data[i] = get_next_line(fd);
		if(get_next_line(fd) == NULL)
			break ;
		i++;
	}
	i = 0;
	while (data[i] != NULL)
	{
		printf("%s", data[i]);
		i++;
	}
}
