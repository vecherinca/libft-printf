/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputkey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:05:43 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/14 00:37:36 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_zoom(int keysym, t_data *data)
{
	if (keysym == 45 && data->zoom_factor > 0.01)
	{
		data->zoom_factor *= 0.9;
		data->movez *= 0.9;
	}
	if (keysym == 61)
	{
		data->zoom_factor *= 1.1;
		data->movez *= 1.1;
	}
	if (keysym == 49)
		data->movez *= 1.1;
	if (keysym == 50)
		data->movez *= 0.9;
}

void	move_move(int keysym, t_data *data)
{
	if (keysym == 65363)
		data->move_x = data->move_x + 1.5;
	if (keysym == 65361)
		data->move_x = data->move_x - 1.5;
	if (keysym == 65362)
		data->move_y = data->move_y - 5;
	if (keysym == 65364)
		data->move_y = data->move_y + 5;
}

void	rotate_rotate(int keysym, t_data *data)
{
	if (keysym == 117)
		data->alpha = data->alpha + 1;
	if (keysym == 105)
		data->alpha = data->alpha - 1;
	if (keysym == 102)
		data->theta = data->theta + 1;
	if (keysym == 100)
		data->theta = data->theta - 1;
	if (data->theta < 0)
		data->theta += 360;
	if (data->theta > 360)
		data->theta -= 360;
	if (data->alpha < 0)
		data->alpha += 360;
	if (data->alpha > 360)
		data->alpha -= 360;
}

int	input_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	zoom_zoom(keysym, data);
	move_move(keysym, data);
	rotate_rotate(keysym, data);
	return (0);
}
