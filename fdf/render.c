/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:31:48 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/14 01:03:19 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
t_cord zoom_and_rotate(float x, float y, float z, t_data *data)
{
	t_cord	res;
	float new_x;
	float new_y;
	float new_z;
	float alpha;
	float beta;
	float theta;


	alpha = data -> alpha * (PI/180);
	beta = data -> beta * (PI/180);
	theta = data -> theta * (PI/180);
	//printf("movez ---> %f\n", data->movez);
	z *= data->movez;
	x = x - data->central_x;
	y = y -  data->central_y;
	z = z - data->central_z;
	x *= data->zoom_factor;
	y *= data->zoom_factor;

	new_x = x * cos(theta) - y * sin(theta);
	new_y = x * sin(theta) + y * cos(theta);
	new_z = z;
	z = new_x * sin(beta) + new_z * cos(beta);
    x = new_x * cos(beta) - new_z * sin(beta);
    y = new_y;
    res.y = y * cos(alpha) - z * sin(alpha);
    res.z = y * sin(alpha) + z * cos(alpha);
    res.x = x;
	res.x += (WINDOW_WIDTH/2);
	res.y +=(WINDOW_HEIGHT/2);
	res.x += data->move_x;
	res.y += data->move_y;

	return (res);
}

int	render_rect(t_img *img, t_tab **table, t_lines cnt, t_data *data)
{
	int		i;
	int		j;
	t_cord	point2;
	t_cord	point1;
	int		color;

	i = 0;
	while (i < cnt.ver_i)
	{
		j = 0; 
		while (j < cnt.hor_j)
		{
			color = table[i][j].color;
			point1 = zoom_and_rotate(table[i][j].x, table[i][j].y, table[i][j].z, data);
			if(i < cnt.ver_i - 1)
			{
				point2 = zoom_and_rotate(table[i + 1][j].x, table[i + 1][j].y, table[i + 1][j].z, data);
				bresenham(point2, point1, img, color);
			}
			if (j < cnt.hor_j - 1)
			{
				point2 = zoom_and_rotate(table[i][j + 1].x, table[i][j + 1].y, table[i][j + 1].z, data);
				bresenham(point2, point1, img, color);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_reverse(t_img *img, t_tab **table, t_lines cnt, t_data *data)
{
	int		i;
	int		j;
	t_cord	point2;
	t_cord	point1;
	int		color;

	i = cnt.ver_i - 1;

	while (i >= 0)
	{
		j = cnt.hor_j - 1;
		while (j >= 0)
		{
			color = table[i][j].color;
			point1 = zoom_and_rotate(table[i][j].x, table[i][j].y, table[i][j].z, data);
			if(i > 0)
			{
				point2 = zoom_and_rotate(table[i - 1][j].x, table[i - 1][j].y, table[i - 1][j].z, data);
				bresenham(point2, point1, img, color);
			}
			if (j > 0)
			{
				point2 = zoom_and_rotate(table[i][j - 1].x, table[i][j - 1].y, table[i][j - 1].z, data);
				bresenham(point2, point1, img, color);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int	render(t_data *data)
{
	int flip;
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	flip = map_is_flipped(data);
	if (flip == -1)
		render_rect(&data->img, data->table, data->cnt, data);
	else
		render_reverse(&data->img, data->table, data->cnt, data); 
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,0);
	return (0);
}

int	draw(t_data data)
{
	//t_data	data;
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