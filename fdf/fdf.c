/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/05/21 01:25:03 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	*name;
	t_lines	cnt;
	t_data	data;

	if (argc == 2)
	{
		cnt.ver_i = 0;
		cnt.hor_j = 0;
		name = argv[1];
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
		//draw(data);
		//freee_tab(data.table, cnt);
	}
	else
		write(1,"Wrong number of arguments", 26);
}
