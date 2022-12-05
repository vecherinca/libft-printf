/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:49:56 by mklimina          #+#    #+#             */
/*   Updated: 2022/12/05 01:04:03 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
# define BUFFER_SIZE 10
char *get_next_line(int fd)
{
	int bytes;
	int i = 0;
	int j = 0;
	char buffer[BUFFER_SIZE];
	static char *stash;

	bytes = read(fd, buffer, BUFFER_SIZE);
	stash = malloc(sizeof(char) * bytes + 1);

	//printf("%d", bytes);
	// printf("%s \n", "****************************");
	printf("%s \n",buffer);
	//let's print it line by line

}
int main()
{
	int fd = open("file.txt", O_RDONLY);
	// if(!fd)
	// 	printf("Masha your file is shit");
	// else
	// 	printf("file descriptor -- > %d\n Masha your file is ok\n", fd);
	// get_next_line(fd);
	get_next_line(fd);
	return(0);
}
