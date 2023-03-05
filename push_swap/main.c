/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:22:45 by maria             #+#    #+#             */
/*   Updated: 2023/03/04 00:23:31 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	head_a	*a;
	head_a	*b;

	if (argc == 1 || argc == 2)
		exit(0);
	a = define_list_a(argc, argv);
	b = define_list_b();
	if (!b)
		return (0);
	check_the_stack(a, b);
	assign_index(a);
	pushswap(a, b, argc);
	free_list(a -> first, a);
	free_list(b -> first, b);

}