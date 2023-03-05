/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhelpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:41:23 by maria             #+#    #+#             */
/*   Updated: 2023/03/04 00:41:37 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

void print_the_list(head_a *head)
{
	a_list *start;
	start = head -> first;
	while(start != NULL)
	{	
		printf("%d\n", start -> content);
        start = start -> next;
	}
}
