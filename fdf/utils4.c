/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:28:58 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/25 23:29:13 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ang	return_angles(t_ang angle, t_data *data)
{
	angle.alpha = data->alpha * (PI / 180);
	angle.beta = data->beta * (PI / 180);
	angle.theta = data->theta * (PI / 180);
	return (angle);
}

t_cord	move_things(t_cord res, t_data *data)
{
	res.x += (WINDOW_WIDTH / 2);
	res.y += (WINDOW_HEIGHT / 2);
	res.x += data->move_x;
	res.y += data->move_y;
	return (res);
}

void	render_instructiontext(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10,
		200, 0x00E5E7E6, "Move around: arrow keys");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		10, 250, 0x00E5E7E6, "Zoom: + / -");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		10, 300, 0x00E5E7E6, "Decrease/increase height  :  1 / 2");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		10, 350, 0x00E5E7E6, "Rotate around Y-axis:  F/D");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		10, 400, 0x00E5E7E6, "Rotate around X-axis:  U/I");
}
