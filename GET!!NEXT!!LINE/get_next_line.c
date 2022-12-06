/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:49:56 by mklimina          #+#    #+#             */
/*   Updated: 2022/12/06 22:08:50 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#define BUFFER_SIZE 15



int check_the_line(char *buffer)
{
	//this function checks if 
	//we have a \n \0 in a string 
	
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

void *fill_the_stash(char *buffer, char *stash)
{
	// here we need to manage the stash one more time
	char *line;
	while(!check_the_line(stash))
	{
		line = ft_strjoin(stash, buffer);
	}
	printf("%s", line);
	return(line);
}

char	*get_next_line(int fd)
{
	int		bytes;
	// int		i;
	static char	buffer[BUFFER_SIZE];
	char *stash;
	
	stash = malloc(ft_strlen(buffer) * sizeof(char) + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	stash[BUFFER_SIZE+1] = '\0';
	printf("this is your buffer ----> %s\n", buffer);
	printf("*****************************\n");
	// so what we do now is literally filling the first processing of the stash
	// to fix it later
	ft_strlcpy(stash, buffer, ft_strlen(buffer)+1);
	printf("this is your stash ----> %s\n", stash);
	bytes = bytes;
	//but here I don't get like if we launch the func in a loop 
	//how in the world we enter the fucking loop
	// let's try like this now
	
	while (!check_the_line(buffer))
	{
		//now the buffer is filled till the '\n'
		bytes = read(fd, buffer, BUFFER_SIZE);
		fill_the_stash(buffer, stash);	
		//here u parse the thing to your stash
		
		
	}
	
	return (NULL);
}


int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	// if(!fd)
	// 	printf("Masha your file is shit");
	// else
	// 	printf("file descriptor -- > %d\n Masha your file is ok\n", fd);
	// get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	return (0);
}
