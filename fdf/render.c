/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:31:48 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/18 20:19:18 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cord	zoom_n_rot(float x, float y, float z, t_data *data)
{
	t_cord	res;
	float	new_x;
	float	new_y;
	float	new_z;
	t_ang	angle;

	angle = return_angles(angle, data);
	z *= data->movez;
	x = x - data->central_x;
	y = y - data->central_y;
	z = z - data->central_z;
	x *= data->zoom_factor;
	y *= data->zoom_factor;
	new_x = x * cos(angle.theta) - y * sin(angle.theta);
	new_y = x * sin(angle.theta) + y * cos(angle.theta);
	new_z = z;
	z = new_x * sin(angle.beta) + new_z * cos(angle.beta);
	x = new_x * cos(angle.beta) - new_z * sin(angle.beta);
	y = new_y;
	res.y = y * cos(angle.alpha) - z * sin(angle.alpha);
	res.z = y * sin(angle.alpha) + z * cos(angle.alpha);
	res.x = x;
	res = move_things(res, data);
	return (res);
}

int	render_rect(t_img *img, t_tab **t, t_lines cnt, t_data *d)
{
	int		i;
	int		j;
	t_cord	p2;
	t_cord	p1;

	i = 0;
	while (++i < cnt.ver_i)
	{
		j = 0;
		while (++j < cnt.hor_j)
		{
			p1 = zoom_n_rot(t[i][j].x, t[i][j].y, t[i][j].z, d);
			if (i < cnt.ver_i - 1)
			{
				p2 = zoom_n_rot(t[i + 1][j].x, t[i + 1][j].y, t[i + 1][j].z, d);
				bresenham(p2, p1, img, t[i][j].color);
			}
			if (j < cnt.hor_j - 1)
			{
				p2 = zoom_n_rot(t[i][j + 1].x, t[i][j + 1].y, t[i][j + 1].z, d);
				bresenham(p2, p1, img, t[i][j].color);
			}
		}
	}
	return (0);
}

int	render_reverse(t_img *img, t_tab **t, t_lines cnt, t_data *d)
{
	int		i;
	int		j;
	t_cord	p2;
	t_cord	p1;

	i = cnt.ver_i;
	while (--i >= 0)
	{
		j = cnt.hor_j;
		while (--j >= 0)
		{
			p1 = zoom_n_rot(t[i][j].x, t[i][j].y, t[i][j].z, d);
			if (i > 0)
			{
				p2 = zoom_n_rot(t[i - 1][j].x, t[i - 1][j].y, t[i - 1][j].z, d);
				bresenham(p2, p1, img, t[i][j].color);
			}
			if (j > 0)
			{
				p2 = zoom_n_rot(t[i][j - 1].x, t[i][j - 1].y, t[i][j - 1].z, d);
				bresenham(p2, p1, img, t[i][j].color);
			}
		}
	}
	return (0);
}

int	render(t_data *data)
{
	int	flip;

	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	flip = map_is_flipped(data);
	if (flip == -1)
		render_rect(&data->img, data->table, data->cnt, data);
	else
		render_reverse(&data->img, data->table, data->cnt, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	draw(t_data data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &input_key, &data);
	mlx_key_hook(data.win_ptr, &input_key, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
