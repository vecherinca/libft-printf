/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:37 by mklimina          #+#    #+#             */
/*   Updated: 2023/07/31 20:26:04 by mklimina         ###   ########.fr       */
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
				

typedef struct t_a_list
{
	char *path;
	
	char *all;
	
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

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strstr(char *str, char *to_find);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);

#endif