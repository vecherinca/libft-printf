/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:49:56 by mklimina          #+#    #+#             */
/*   Updated: 2022/12/11 19:12:23 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

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
	if(i == 0)
		return(NULL);
	line = ft_calloc(sizeof(char), i + 2);
	if(!line)
		return(NULL);
	i = 0;
	while (stash[i]!='\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i]!= '\0')
		line[i] = '\n';
	return(line);
}

char *init_stash(char *stash, char *buffer, int fd)
{
	int bytes;
	
	bytes = 0;
	if (buffer[0] == '\0')
		bytes = read(fd, buffer, BUFFER_SIZE);
	stash = NULL;
	bytes = bytes;	
	stash = ft_strjoin("", buffer);
	return(stash);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char		*stash;
	char		*line;
	int			bytes; 
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	bytes = 1;
	stash = "";
	stash = init_stash(stash, buffer, fd);
	if(stash == NULL)
		return(NULL);
	while ((bytes != 0 && check_the_line(buffer)!=1) || bytes == -1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		bytes = read(fd, buffer,BUFFER_SIZE);
		if ((bytes == 0 && check_the_line(buffer) == 0) || (bytes == -1))
			break;
		line = ft_strdup(stash);
		free(stash);
		stash = ft_strjoin(line, buffer);
		free(line);
	}
	if(*stash == '\n')
		return(stash);
	line = get_the_line(stash);
	clean_stash(stash, buffer);
	return(free(stash), line);
}

// int	main(void)
// {
// 	int	fd;
// 	fd = open("nl", O_RDONLY);
// 	char *str;
	
// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);
	
// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);
	
// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);

// 	str = get_next_line(fd);
// 	printf("%s",str);
// 	free(str);
// }
// int main(void)
// {
// 	int i;
// 	int fd;
// 	fd = open("file.txt", O_RDONLY);
// 	i = 0;

// 	while (i < 12)
// 	{
// 		printf("line num %d ---- > %s", i, get_next_line(fd));
// 		i++;
// 	}
// }