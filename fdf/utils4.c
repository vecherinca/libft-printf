/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:28:58 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/18 20:22:39 by mklimina         ###   ########.fr       */
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
