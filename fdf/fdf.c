/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/05/18 20:33:36 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	*name;
	t_lines	cnt;
	t_data	data;

	cnt.ver_i = 0;
	cnt.hor_j = 0;
	name = argv[1];
	(void)argc;
	cnt = count_columns(name, cnt);
	data.table = create_ttable(name, cnt);
	cnt.max = find_max(data.table, cnt);
	cnt.min = find_min(data.table, cnt);
	data = init(data, cnt);
	data.cnt.hor_j = cnt.ver_i;
	data.cnt.ver_i = cnt.hor_j;
	data.central_x = (data.cnt.hor_j) / 2;
	data.central_y = (data.cnt.ver_i) / 2;
	data.central_z = find_z(data.table, cnt);
	draw(data);
	freee_tab(data.table, cnt);
}
