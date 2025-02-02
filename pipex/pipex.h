/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:37 by mklimina          #+#    #+#             */
/*   Updated: 2023/08/13 23:01:15 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include <sys/wait.h>

typedef struct t_a_list
{
	char *path;
	char **cmd;
	struct t_a_list	*next;
}					t_a_list;

typedef struct t_head_a
{
	t_a_list		*first;
}	t_head_a;

typedef struct t_pipex
{
	int	file1;
	int	file2;	
	int cmd_count;
	char **paths;
	char **cmds;
	char **args;
	t_head_a *cmd;
	
}t_pipex;
void print(t_pipex pipex);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strstr(char *str, char *to_find);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
void	ft_lstadd_back(t_a_list **lst, t_a_list *new);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_2dim(char **to_free);
void execute(t_pipex pipex, char **env);
void	free_list(t_a_list *head, t_head_a *main);
void init_child(int count, t_pipex pipex, char **env, t_a_list *cmd);
#endif