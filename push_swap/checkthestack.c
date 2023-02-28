/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkthestack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:37:38 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/01 00:02:22 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checkthearg(char *arg)
{	
	char *test;
	test = ft_itoa(ft_atoi(arg));
	if (ft_strcmp(test, arg) != 0)
		return(0);
	return(1);
}
