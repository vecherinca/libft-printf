/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/05/12 20:39:36 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define PI 3.14159265358979323846
int	input_key(int keysym, t_data *data)
{
	// printf("beta ----> %f\n", data -> beta);
	// printf("alpha ----> %f\n", data -> alpha);
	// printf("theta ----> %f\n", data -> theta);
	printf("keysym ----> %d\n", keysym);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (keysym == 45 && data->zoom_factor> 0.01)
	{
		data->zoom_factor= data->zoom_factor - 0.1;
		printf("data->zoom_factor moins ---> %f\n", data->zoom_factor);
	}
	if (keysym == 61)
	{
		data->zoom_factor= data->zoom_factor + 0.1;
		printf("data->zoom_factor plus ---> %f\n", data->zoom_factor);
	}
	if (keysym == 65363)
		data->move_x = data->move_x * 1.5;
	if (keysym == 65361)
		data->move_x = data->move_x / 1.5;
	if (keysym == 65362)
		data->move_y = data->move_y - 5;
	if (keysym == 65364)
		data->move_y = data->move_y + 5;
	if (keysym == 32)
	{
		data ->beta = data->beta + 1;
		printf("beta---> %f\n", data ->beta);
	}
	if (keysym == 117)
	{
		data ->alpha = data->alpha + 1;
		printf("alpha---> %f\n", data ->alpha);
	}
	if (keysym == 100)
	{
		data -> theta = data->theta + 1;
		printf("theta---> %f\n", data ->theta);
	}
	if (keysym == 49)
		data -> movez *= 1.1;
	if (keysym == 50)
		data -> movez /= 1.1;
	return (0);
}

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

/*
t_point	new_point;

first : zoom;

new_point = zoom(data, table[i][j].x, table[i][j].y, table[i][j].z);
new_point1 = zoom(data, table[i + stuff][j].x, table[i][j].y, table[i][j].z);

new_point = rotation(data, new_point);
new_point1 = rotation(data, new_point1);

project to screen;
translate here maybe ?;
draw lines;
*/
t_cord zoom_and_rotate(float x, float y, float z, t_lines cnt, t_data *data)
{
	t_cord	res;
	float new_x;
	float new_y;
	float new_z;
	float alpha;
	float beta;
	float theta;

	(void) cnt;
	alpha = data -> alpha * (PI/180);
	beta = data -> beta * (PI/180);
	theta = data -> theta * (PI/180);
	
	z *= data->movez;
	x = x - data->central_x;
	y = y -  data->central_y;
	z = z - data->central_z;
	x *= data->zoom_factor;
	y *= data->zoom_factor;
	z *= data -> zoom_factor/2;
	// printf("x: %f\n", x);
	// printf("y: %f\n", y);
	// printf("z: %f\n", z);
	// x += data->move_x;
	// y += data->move_y;

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
			point1 = zoom_and_rotate(table[i][j].x, table[i][j].y, table[i][j].z, cnt, data);
			if(i < cnt.ver_i - 1)
			{
				point2 = zoom_and_rotate(table[i + 1][j].x, table[i + 1][j].y, table[i + 1][j].z, cnt, data);
				bresenham(point2, point1, img, color);
			}
			if (j < cnt.hor_j - 1)
			{
				point2 = zoom_and_rotate(table[i][j + 1].x, table[i][j + 1].y, table[i][j + 1].z, cnt, data);
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

	while (i > 0)
	{
		j = cnt.hor_j - 1; //same
		while (j > 0)
		{
			color = table[i][j].color;
			point1 = zoom_and_rotate(table[i][j].x, table[i][j].y, table[i][j].z, cnt, data);
			if(i < cnt.ver_i - 1)
			{
				point2 = zoom_and_rotate(table[i + 1][j].x, table[i + 1][j].y, table[i + 1][j].z, cnt, data);
				bresenham(point2, point1, img, color);
			}
			if (j < cnt.hor_j - 1)
			{
				point2 = zoom_and_rotate(table[i][j + 1].x, table[i][j + 1].y, table[i][j + 1].z, cnt, data);
				bresenham(point2, point1, img, color);
			}
			j--;
		}
		i--;
	}
	return (0);
}

int map_is_flipped(t_data *data)
{
	int value;
	
	if (data -> theta > 90 && data -> theta < 272)
		value = 1;
	else
		value = -1;
	
	return(value);
	
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

t_lines	count_columns(char *name, t_lines cnt)
{
	//int		ccnt;
	char	*line;
	int		fd;
	char	**the_line;
	int		i;
	
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	the_line = ft_split(line, 32);
	cnt.ver_i = count_col(the_line);
	i = -1;
	while (the_line[++i + 1])
		continue ;
	if (the_line[i][0] == '\n')
		cnt.ver_i--;

	while (line)
	{
		line = get_next_line(fd);
		free(line);
		cnt.hor_j++;
	}
	printf("lines  ---> %f\n", cnt.hor_j);
	printf("ccnt ---> %f\n", cnt.ver_i);
	
	return (cnt);
}

t_data init(t_data data)
{

	data.central_x = 0;
	data.central_y = 0;
	data.central_z = 0;
	data.zoom_factor = 23;
	data.move_x = 1;
	data.move_y = 1;
	data.alpha = 61;
	data.beta = 0;
	data.theta = 35;
	data.movez = 1;
	return(data);
}
int	main(int argc, char **argv)
{
	char	*name;
	t_tab	**table;
	t_lines	cnt;
	t_data	data;
	cnt.ver_i = 0;
	cnt.hor_j = 0;
	name = argv[1];
	data = init(data);

	(void)argc;
	(void)data;

	cnt = count_columns(name, cnt);
	table = create_ttable(name, cnt);
	// print(table, cnt);
	// printf("ver_i ---> %f\n", cnt.ver_i);
	// printf("hor_j ---> %f\n", cnt.hor_j);
	data.table = table;
	data.cnt.hor_j =cnt.ver_i;
	data.cnt.ver_i = cnt.hor_j;;
	// //printf("cnt : %f, %f\n", cnt.ver_i, cnt.hor_j);
	//this thing is in question
	data.central_x = (data.cnt.hor_j) / 2;
	data.central_y = (data.cnt.ver_i ) / 2;
	data.central_z = find_z(table,cnt);
	// printf("data x %f",data.central_x);
	// printf("data z %f",data.central_z);
// 	/*************Part MLX ********************/
	draw(data);
}
