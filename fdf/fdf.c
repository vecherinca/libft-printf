/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/04/20 22:09:12 by mklimina         ###   ########.fr       */
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
	if (keysym == 45 && data->dezoom > 0.01)
		data->dezoom = data->dezoom - 0.01;
	if (keysym == 61)
		data->dezoom = data->dezoom + 0.01;
	if (keysym == 65363)
		data->move_x = data->move_x - 1;
	if (keysym == 65361)
		data->move_x = data->move_x + 1;
	if (keysym == 65362)
		data->move_y = data->move_y + 1;
	if (keysym == 65364)
		data->move_y = data->move_y - 1;
	if (keysym == 32)
		data ->beta = data->beta + 2;
	if (keysym == 117)
		data ->alpha = data->alpha + 2;
	if (keysym == 100)
		data -> theta = data->theta + 2;
	// if (keysym == 108)
	// 	data->rot -= 0.1;
	if (keysym == 49)
		data -> movez+= 1;
	if (keysym == 50)
		data -> movez-= 1;
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
void	bresenham(t_cord value, t_img *img, int color)
{
	float	x_step;
	float	y_step;
	int		i;
	float	max_step;

	i = 0;
	x_step = value.x1 - value.x;
	y_step = value.y1 - value.y;
	max_step = max(mod(x_step), mod(y_step));
	x_step /= max_step;
	y_step /= max_step;
	//printf("max_step ----> %f\n", max_step);
	while (i < max_step)
	{
		//printf(" max step ----> %f\n", max_step);
		img_pix_put(img, value.x, value.y, color);
		value.x += x_step;
		value.y += y_step;
		i++;
	}
}

float modify_x(float x, float y, float z, t_data *data, t_lines cnt)
{
	float res;
	float new_x;
	float new_y;
	// float cos_rot = cos(data->rot * (PI/180)); // transorm radian
	// float sin_rot = sin(data->rot * (PI/180)); // transorm radian
	data -> alpha = data -> alpha * (PI/180);
	data -> beta = data -> beta * (PI/180);
	data -> theta = data -> theta * (PI/180);
	
	printf("beta ----> %f\n", data -> beta);
	printf("alpha ----> %f\n", data -> alpha);
	printf("theta ----> %f\n", data -> theta);
	
	new_x = (x * cos(data ->alpha) * cos(data ->beta)) 
	+ (y * ((cos(data -> alpha) * sin(data ->beta) * sin(data -> theta)) 
	- (sin(data ->alpha) * cos(data -> theta))) 
	+ (z * ((cos(data -> alpha) * sin(data -> beta) * cos(data -> theta)) 
	+ (sin(data -> alpha) * sin(data -> theta))))); 
	printf("new_x ----> %f\n", new_x);
	exit(1);
	new_y = (x * sin(data ->alpha) * cos(data ->beta)) 
	+ (y * ((sin(data -> alpha) * sin(data ->beta) * sin(data -> theta)) 
	+ (cos(data ->alpha) * cos(data -> theta))) 
	+ (z * ((sin(data -> alpha) * sin(data -> beta) * cos(data -> theta)) 
	- (cos(data -> alpha) * sin(data -> theta)))));
	printf("new_x ----> %f\n", new_x);

	res = (((new_x * data->point64 - new_y * data->point64) * data -> dezoom) + WINDOW_WIDTH / 2) -
	 (((cnt.ver_i - cnt.hor_j) * 64) / 2) *data -> dezoom + data->move_x;
	return(res);
// 	printf("beta ----> %f\n", data -> beta);
// 	printf("alpha ----> %f\n", data -> alpha);
// 	printf("theta ----> %f\n", data -> theta);
}

float modify_y(float x, float y, float z, t_lines cnt, t_data *data)
{
	float res;
	float new_x;
	float new_y;
	float new_z;
	
	data -> alpha = data -> alpha * (PI/180);
	data -> beta = data -> beta * (PI/180);
	data -> theta = data -> theta * (PI/180);
	// printf("movez ----> %d\n", data -> movez);
	
	new_x = (x * cos(data ->alpha) * cos(data ->beta)) 
	+ (y * ((cos(data -> alpha) * sin(data ->beta) * sin(data -> theta)) 
	- (sin(data ->alpha) * cos(data -> theta))) 
	+ (z * ((cos(data -> alpha) * sin(data -> beta) * cos(data -> theta)) 
	+ (sin(data -> alpha) * sin(data -> theta))))); 

	new_y = (x * sin(data ->alpha) * cos(data ->beta)) 
	+ (y * ((sin(data -> alpha) * sin(data ->beta) * sin(data -> theta)) 
	+ (cos(data ->alpha) * cos(data -> theta))) 
	+ (z * ((sin(data -> alpha) * sin(data -> beta) * cos(data -> theta)) 
	- (cos(data -> alpha) * sin(data -> theta)))));

	new_z = (x * (-1 * sin(data -> beta))) 
	+ (y * (cos(data -> beta) * sin(data -> theta))) 
	+ (z *(cos(data -> beta)) * cos(data -> theta));
	// float cos_rot = cos(data->rot * (PI/180)); // transorm radian
	// float sin_rot = sin(data->rot * (PI/180)); // transorm radian
	
	res =  ((((new_x  * data->point32 + new_y  * data->point32) * data -> dezoom) + (WINDOW_HEIGHT / 2) 
	- (((cnt.ver_i + cnt.hor_j) * 32) / 2) *data -> dezoom - (new_z * data->movez) * data -> dezoom)) + data->move_y;
	return(res); 
}

int	render_rect(t_img *img, t_tab **table, t_lines cnt, t_data *data)
{
	int		i;
	int		j;
	t_cord	value;
	int		color;

	i = 0;
	value.x = 0;
	value.y = 0;
	value.x1 = 0;
	value.y1 = 0;
	data -> alpha = 45;
	data -> beta = 1;
	data -> theta = 0;
	while (i < cnt.ver_i)
	{
		j = 0;
		while (j < cnt.hor_j)
		{
			color = table[i][j].color;
			value.x = modify_x(table[i][j].x, table[i][j].y, table[i][j].z, data, cnt);
			value.y = modify_y(table[i][j].x, table[i][j].y,table[i][j].z, cnt, data);
			if(i < cnt.ver_i - 1)
			{
				value.x1 = modify_x(table[i + 1][j].x, table[i + 1][j].y, table[i][j].z, data, cnt);
				value.y1 = modify_y(table[i + 1][j].x, table[i + 1][j].y,table[i + 1][j].z, cnt, data);
				bresenham(value, img, color);
			}
			if (j < cnt.hor_j - 1)
			{
				value.x1 = modify_x(table[i][j + 1].x, table[i][j + 1].y, table[i][j].z, data, cnt);
				value.y1 = modify_y(table[i][j + 1].x, table[i][j + 1].y,table[i][j + 1].z, cnt, data);
				bresenham(value, img, color);
			}
			j++;
			// printf("alpha ----> %f\n", data -> alpha);
			// printf("movez ----> %d\n", data->movez);
			// printf("beta ----> %f\n", data -> beta);
			// printf("beta ----> %f\n", data -> beta);
			// printf("alpha ----> %f\n", data -> alpha);
			// printf("theta ----> %f\n", data -> theta);
			// printf("movez ----> %f\n", data -> movez);
			// printf("x ----> %f\n", value.x);
			// printf("y ----> %f\n", value.y);
		}
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	render_rect(&data->img, data->table, data->cnt, data);
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
	//printf("beforeeeeeeeeeeeeeeeeee alpha----> %f\n", data.alpha);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &input_key, &data);
	mlx_key_hook(data.win_ptr, &input_key, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

int	count_columns(char *name)
{
	int		ccnt;
	char	*line;
	int		fd;
	char	**the_line;
	int		i;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	the_line = ft_split(line, 32);
	ccnt = count_col(the_line);
	i = -1;
	while (the_line[++i + 1])
		continue ;
	if (the_line[i][0] == '\n')
		ccnt--;
	return (ccnt);
}

int	main(int argc, char **argv)
{
	char	*name;
	t_tab	**table;
	t_lines	cnt;
	t_data	data;

	//int ccnt;
	//what to connect
	cnt.ver_i = 0;
	cnt.hor_j = 0;
	data.dezoom = 1;
	data.move_x = 1;
	data.move_y = 1;
	
	data.point32 = 32;
	data.movez = 1;
	data.point64 = 64; // I transform to the radiam
	// printf("beta ----> %f\n", data.beta);
	// printf("alpha ----> %f\n", data.alpha);
	// printf("theta ----> %f\n", data.theta);
	// printf("movez ----> %d\n", data.movez);
	printf("***");
	(void)argc;
	name = argv[1];
	//ccnt = count_lines(name);
	cnt.ver_i = count_lines(name);
	cnt.hor_j = count_columns(name);
	table = create_ttable(name);
	table = table;
	//print(table, ccnt);
	//printf("i -----> %d\n", cnt.ver_i);
	//printf("j -----> %d\n", cnt.hor_j);
	data.table = table;
	data.cnt.hor_j = cnt.hor_j;
	data.cnt.ver_i = cnt.ver_i;
// 	/*************Part MLX ********************/
	draw(data);
}
