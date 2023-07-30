/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:37 by mklimina          #+#    #+#             */
/*   Updated: 2023/07/30 19:38:08 by mklimina         ###   ########.fr       */
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
	char **cmds;
	char **args;
	t_head_a *cmd;
	
}t_pipex;

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);


#endif