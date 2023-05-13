/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:39:42 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/13 23:54:57 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float num)
{
	if (num >= 0)
		return (num);
	else
		return (-1 * num);
}

float	max(float x_step, float y_step)
{
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}
void	bresenham(t_cord point2, t_cord point1, t_img *img, int color)
{
	float	x_step;
	float	y_step;
	int		i;
	float	max_step;

	i = 0;
	x_step = point2.x - point1.x;
	y_step = point2.y - point1.y;
	max_step = max(mod(x_step), mod(y_step));
	x_step /= max_step;
	y_step /= max_step;
	while (i < max_step)
	{
		img_pix_put(img, point1.x, point1.y, color);
		point1.x += x_step;
		point1.y += y_step;
		i++;
	}
}
