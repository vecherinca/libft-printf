/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/03/09 01:18:08 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int count_lines(char *name)
{
	int		fd;
	char	*str;
	int		count; 
	fd = open(name, O_RDONLY);
	str = get_next_line(fd);
	count = 0;
	while(str)
	{
		str = get_next_line(fd);
		count++;
	}
	free(str);
	return (count);
	
}
int	main(int argc, char **argv)
{
	char	*name;
	int 	fd;
	char 	*str;
	char	**data;
	//int 	cnt;
	(void) argc;
	(void) data;
	name = argv[1];
	fd = open(name, O_RDONLY);
	printf("my arg ---> %s\n", name);
	printf("my fd ---> %d\n", fd);
	//cnt = count_lines(name);
	//printf("LINES IN A FILE ---> %d\n", cnt);
	str = get_next_line(fd);
	int i = 1;
	while (str)
	{	
		printf("LINE num %i --> %s", i, str);
		str = get_next_line(fd);
		i++;
	}
	free(str);
	
	
	
}
