/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:15:27 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/07 19:23:51 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "gnl/get_next_line.h"

int	checksstr(char *sstr)
{
	if (ft_strcmp(sstr, "sa\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "sb\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "pa\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "pb\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "ra\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "rb\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "rr\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "rra\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "rrb\n") == 0)
		return (1);
	if (ft_strcmp(sstr, "rrr\n") == 0)
		return (1);
	return (0);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
