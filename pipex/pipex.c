/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:15 by mklimina          #+#    #+#             */
/*   Updated: 2023/08/23 00:03:02 by maria            ###   ########.fr       */
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
	pipex.file1 = open(argv[1], O_RDONLY);
	pipex.file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex.cmd_count = argc - 3; 
	pipex.cmd = define_list(argc, argv, pipex);
	return(pipex);
}

void init_child(int count, t_pipex pipex, char **env, t_a_list *cmd)
{
	int fd[2];
	pipe(fd);
	pid_t pid; 
	pid = fork();
	if (pid == 0)
	{
		if (count == 0)
		{
			dup2(pipex.file1, STDIN_FILENO);
			dup2(fd[1], STDOUT_FILENO);
		}
		if (count == pipex.cmd_count - 1)
			dup2(pipex.file2, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		execve(cmd -> path, cmd ->cmd, env);
		close(fd[0]);
	}
	else
	{
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}	
}

void execute(t_pipex pipex, char **env)
{
	int i = 0;
	t_a_list *cmd;
	cmd = pipex.cmd -> first;
	while (cmd != NULL)
	{
		init_child(i, pipex, env, cmd);
		cmd = cmd -> next;
		i++;
	}
	
}

void parse(int argc, char **argv, char **env)
{
	int i;
	t_pipex pipex;
	pipex = init(argv, pipex, argc, env);
	//print(pipex);
	execute(pipex, env);	
}
int	main(int argc, char **argv, char **env)
{
	parse(argc, argv, env);				
}
