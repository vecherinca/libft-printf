/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:43:34 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/25 23:04:32 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	transform_z(t_lines cnt)
{
	float	factor;

	if (cnt.max == 0 && cnt.min == 0)
		return (1.0);
	if (mod(cnt.max) > mod(cnt.min))
		factor = WINDOW_HEIGHT / (16 * mod(cnt.max));
	else
		factor = WINDOW_HEIGHT / (16 * mod(cnt.min));
	return (factor);
}

t_data	init(t_data data, t_lines cnt)
{
	float	zoom_zoom;
	float	z_z;

	zoom_zoom = returnzoom(cnt);
	z_z = transform_z(cnt);
	data.central_x = 0;
	data.central_y = 0;
	data.central_z = 0;
	data.zoom_factor = zoom_zoom;
	data.move_x = 1;
	data.move_y = 1;
	data.alpha = 60;
	data.beta = 0;
	data.theta = 45;
	data.movez = z_z;
	return (data);
}
