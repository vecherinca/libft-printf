/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhelpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:41:23 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 19:12:34 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void print_the_list(t_head_a *head)
{
	t_a_list *start;
	start = head -> first;
	while(start != NULL)
	{	
		printf("%d\n", start -> content);
        start = start -> next;
	}
}
