/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:49:56 by mklimina          #+#    #+#             */
/*   Updated: 2022/12/11 01:30:51 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#define BUFFER_SIZE 100

int check_the_line(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

char	*clean_stash(char *stash, char *buffer)
{
	int		i;
	int		j;


	i = 0;
	j = 0;
	while (stash[i]!='\n' && stash[i] != '\0')
		i++;
	ft_bzero(buffer, BUFFER_SIZE);
	if (stash[i] != '\0')
		i++;
	while (stash[i]!= '\0')
	{
		buffer[j] = stash[i];
		i++;
		j++;
	}
	return(0);
}

char *get_the_line(char *stash)
{
	char *line;
	int i;

	i = 0;
	line = NULL;
	while (stash[i]!='\n' && stash[i] != '\0')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	i = 0;
	while (stash[i]!='\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (i == 0)
		return(NULL);
	line[i] = '\n';
	return(line);
}

char *init_stash(char *stash, char *buffer, int fd)
{
	int bytes;
	
	bytes = 0;
	if (buffer[0] == '\0')
		bytes = read(fd, buffer, BUFFER_SIZE);	
	stash = malloc(sizeof(char) * bytes + 1);
	if(!stash)
		return(NULL);
	stash[bytes] = '\0';		
	stash = ft_strjoin("", buffer);
	return(stash);
}

char	*get_next_line(int fd)
{

	static char buffer[BUFFER_SIZE];
	char		*stash;
	char		*line;
	int			bytes; 
	
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	stash = "";
	stash = init_stash(stash, buffer, fd);
	// printf("this is our stash after init---- > %s\n", stash);
	
	while (bytes != 0 && check_the_line(buffer)!=1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		bytes = read(fd,buffer,BUFFER_SIZE);
		if (bytes == 0 && check_the_line(buffer) == 0)
			break;
		line = ft_strdup(stash);
		free(stash);
		stash = malloc(sizeof(char) * bytes + ft_strlen(line) + 1);
		stash = ft_strjoin(line, buffer);
		free(line);
	}
	line = get_the_line(stash);
	clean_stash(stash, buffer);
	return(free(stash), line);
}


int	main(void)
{
	int	fd;
	fd = open("file.txt", O_RDONLY);
	char *str;
	
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s",str);
	free(str);

	str = get_next_line(fd);
	printf("%s",str);
	free(str);

	str = get_next_line(fd);
	printf("%s",str);
	free(str);
}