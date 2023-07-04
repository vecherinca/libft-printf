/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:37 by mklimina          #+#    #+#             */
/*   Updated: 2023/07/04 20:56:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_a_list
{
	char 			*content;
	struct t_a_list	*next;
}					t_a_list;

typedef struct t_head_a
{
	t_a_list		*first;
}					t_head_a;


#endif