/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:15 by mklimina          #+#    #+#             */
/*   Updated: 2023/07/31 20:33:39 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"

void	ft_lstadd_back(t_a_list **lst, t_a_list *new)
{
	t_a_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_a_list	*create_list(int argc, char **argv, t_head_a *point)
{
	t_a_list	*temp;
	t_a_list	*head;
	int			i;
	(void) point; 
	head = NULL;
	i = 2;
	while (i < argc - 1)
	{
		// if (checkthearg(argv[i]) == 0)
		// {
		// 	write(2, "Error\n", 6);
		// 	free_list(head, point);
		// 	exit(0);
		// }
		temp = malloc(sizeof(t_a_list));
		if (!temp)
			return (NULL);
		temp->all = argv[i];
		//printf("all -> %s\n", temp-> all);
		//ft_split(argv[i], ' ');
		temp->cmd = ft_split(argv[i], ' ');
		temp->next = NULL;
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

t_head_a	*define_list(int argc, char **argv)
{
	t_head_a	*point;

	point = malloc(sizeof(t_head_a));
	if (!point)
		return (NULL);
	point->first = create_list(argc, argv, point);
	return (point);
}

void print(t_pipex pipex)
{
	int j = 0;
	t_a_list *current_node = pipex.cmd->first;
	while (current_node != NULL)
	{
		char **cmd_array = current_node->cmd;
		int i = 0;
		while (cmd_array[i] != NULL)
		{
			printf("cmd [%d]> %s\n", j, cmd_array[i]);
			i++;
		}
		j++;
    current_node = current_node->next;
	} 
}

char **parse_env(char **env)
{
	int i;
	char *prefix = "PATH=";
	char *path;
	i = 0;
	while(env[i] != NULL)
	{
		if (ft_strncmp(env[i], prefix, ft_strlen(prefix)) == 0)
		{
			path = ft_strstr(env[i], "PATH=");
			return(ft_split(path, ':'));
		}
		i++;
			
	}
	return(0);
}
t_pipex init(char **argv, t_pipex pipex, int argc, char **env)
{
	pipex.paths = parse_env(env);
	pipex.file1 = open(argv[1], O_RDONLY); // question opening files
	pipex.file2 = open(argv[argc - 1], O_RDONLY);
	pipex.cmd_count = argc - 3; // so you need -1 pipes
	pipex.cmd = define_list(argc, argv);
	
	return(pipex);
}
void parse(int argc, char **argv, char **env)
{
	// we need a structure here 

	// in terms of 1,2,3
	// first I guess we create a pipe
	// then once command executed we 
	// I think you need to take it directly tho
	int i;

	t_pipex pipex;
	pipex = init(argv, pipex, argc, env);
	//printf("argc %d", argc);
	//printf("");
	//printf("number cmd -> %d", pipex.cmd_count);
	// int pipefd[2];
	// pipe(pipefd);
	i = 2;
	while (i < argc-1)
	{
		//printf("iterate -> %s\n", argv[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	parse(argc, argv,env);
	// char **str;
	// str = ft_split(argv[0], ' ');
	// str = str;
	//printf("Hehheh envp -> %s", envp[0]);
	// int fd;
	//  char str1[20] = {0}; 
	// (void) argc;
	// (void) argv;
	// fd = open("/mnt/nfs/homes/mklimina/Desktop/42cursus/pipex/file1.txt", O_RDONLY);
	// printf("well argc -> %d\n", argc);
	// dup2(fd, 0);
	// close(fd);
	// printf("Entered Name: %s\n", str1);
	// scanf("%19s", str1);
	// printf("Entered Name: %s\n", str1);
	// printf("This is printed in example.txt!\n");
				
}
