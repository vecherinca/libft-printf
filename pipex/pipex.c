/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:15 by mklimina          #+#    #+#             */
/*   Updated: 2023/08/21 00:34:24 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include <sys/wait.h>

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

char *get_path(char *cmd, t_pipex pipex)
{
	char *path;
	int flag;
	int i;
	i = 0;
	while (pipex.paths[i] !=  NULL)
	{
		path = ft_strjoin(ft_strjoin(pipex.paths[i], "/"), cmd);
		if (access(path, R_OK) != -1)
		{
			flag = 1;
			printf("I have a permission to %s\n", path);
			return(path);
		}
		else
			flag = 0;
		i++;
	}
	if (flag == 0)
	{
		printf("Command %s does not exist", cmd);
		exit(23);
		// do not forget to free shit
	}
	return(0);
	//printf("pipex.paths->  %s\n", pipex.paths[0]);
}

t_a_list	*create_list(int argc, char **argv, t_head_a *point, t_pipex pipex)
{
	t_a_list	*temp;
	t_a_list	*head;
	int			i;
	(void) point; 
	head = NULL;
	i = 2;
	while (i < argc - 1)
	{
		temp = malloc(sizeof(t_a_list));
		if (!temp)
			return (NULL);
		temp->all = argv[i];
		temp->cmd = ft_split(argv[i], ' ');	
		temp -> path = get_path(temp->cmd[0], pipex);
		temp->next = NULL;
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

t_head_a	*define_list(int argc, char **argv, t_pipex pipex)
{
	t_head_a	*point;

	point = malloc(sizeof(t_head_a));
	if (!point)
		return (NULL);
	point->first = create_list(argc, argv, point, pipex);
	return (point);
}

void print(t_pipex pipex)
{
	t_a_list *current_node = pipex.cmd->first;
	while (current_node != NULL)
	{
			printf("cmd ----> %s\n", current_node -> path);
			printf("args----> %s\n", current_node -> all);
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
	// here we parsed all the env  
	pipex.file1 = open(argv[1], O_RDONLY); // question opening files
	pipex.file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex.cmd_count = argc - 3; // so you need -1 pipes
	pipex.cmd = define_list(argc, argv, pipex);
	return(pipex);
}

void init_child(int count, t_pipex pipex)
{
	int fd[2];
	pipe(fd);
	pid_t pid; 
	pid = fork();
	if (pid == 0)
	{
		if (count == 0)
			dup2(pipex.file1, STDIN_FILENO);
		else if (count == pipex.cmd_count -1)
			dup2(pipex.file2, STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	else
		dup2(fd[0], STDERR_FILENO);

}

void execute(t_pipex pipex, char **env)
{
	int i = 0;
	int fd[2];
	pipe(fd);
	pid_t pid1;
	pid_t pid2;
	t_a_list *op;
	op = pipex.cmd -> first;
	t_a_list *op2;
	op2 = pipex.cmd -> first -> next;
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(pipex.file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		execve(op->path, op->cmd, env);
		close(fd[1]);
	}
	else
	{
		wait(NULL);
		
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(pipex.file2, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);	
		execve(op2->path, op2->cmd, env);
		close(fd[0]);
	}
	else
	{
		wait(NULL);
		
	}
	// while (pipex.cmd ->first!= NULL)
	// {
	// 	//printf("check\n");
	// 	init_child(i, pipex);
	// 	execve(pipex.cmd->first->path, pipex.cmd->first->cmd, env);
	// 	pipex.cmd -> first = pipex.cmd -> first -> next;
	// 	i++;
	// }
	// wait(NULL);
	
	
}

void parse(int argc, char **argv, char **env)
{
	int i;

	t_pipex pipex;
	pipex = init(argv, pipex, argc, env);
	print(pipex);
	execute(pipex, env);

	
	
}
int	main(int argc, char **argv, char **env)
{
	parse(argc, argv, env);
	
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
