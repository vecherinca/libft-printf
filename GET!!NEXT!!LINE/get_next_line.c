/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:49:56 by mklimina          #+#    #+#             */
/*   Updated: 2022/12/08 20:17:05 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#define BUFFER_SIZE 15

int check_the_line(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\0' || buffer[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}
char *get_the_line(char *stash)
{
	int i;
	char *line;
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 1);
	line[i] = '\0';
	i = 0;
	while(stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	return(line);
}

void *fill_the_stash(char *buffer, char *stash)
{
	char *line;
	if (!check_the_line(stash))
		{
			line = ft_strjoin(stash, buffer);
			stash = line;
			return(stash);
		}
	return (line);
}

char *clear_the_stash(char *stash)
{
	int i;
	int j;
	char *temp;
	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	temp[ft_strlen(stash) - i + 1] = '\0'; //this doesn't look good lol
	i++;
	while(stash[i] != '\0')
	{
		temp[j] = stash[i];
		i++;
		j++;
	}
	return(temp);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		*line;
	static char	buffer[BUFFER_SIZE];
	char		*stash;
	
	//bytes = read(fd, buffer, BUFFER_SIZE);
	//stash = malloc(BUFFER + 1 * sizeof(char));
	printf("*****************************\n");
	bytes = bytes; 
	buffer[0] = 0;
	while (!check_the_line(buffer))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		stash = fill_the_stash(buffer, stash);		
	}
	line = get_the_line(stash);
	stash = clear_the_stash(stash);
	printf("final line heehehe: %s\n", line);
	return (line);
}


int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	return (0);
}
