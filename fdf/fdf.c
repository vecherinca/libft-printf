/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/04/06 23:32:02 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	input_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data -> win_ptr = NULL;
	}
	return (0);
}

int mod()

void bresenham(float x, float y, float x1, float y1, t_tab **table)
{
	float x_step;
	float y_step;
	int max;
	x_step = x1 - x;
	y_step = y1 - y;

	max = 
}

int render_rect(t_img *img, t_tab **table, t_lines cnt)
{
	int	i;
	int j;
	int x;
	int y;
	int x1;
	int y2;
	
	i = 0;
	//printf("i: %d, j: %d\n", cnt.ver_i, cnt.hor_j);
	while (i < cnt.ver_i - 1)
	{
		j = 0;
		// printf("liam est pas bg");
		while (j < cnt.hor_j)
		{
			x =(table[i][j].x * 64 - table[i][j].y * 64)
			 + WINDOW_WIDTH/2;
			y = ((table[i][j].x * 32 + table[i][j].y * 32)
			  + (WINDOW_HEIGHT/2) - ((cnt.ver_i + cnt.hor_j) * 32)/2) - table[i][j].z;

			x1 = (table[i+1][j].x  * 64 - table[i][j].y * 64)
			 + WINDOW_WIDTH/2;
			y2 = ((table[i][j].x * 32 + table[i][j].y * 32)
			  + (WINDOW_HEIGHT/2) - ((cnt.ver_i + cnt.hor_j) * 32)/2) - table[i][j].z;
			  
			//printf("x: %d, y: %d\n",  table[i][j].x, table[i][j].y);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data -> win_ptr == NULL)
		return (1);
	// render_background(&data->img, WHITE_PIXEL);	
	render_rect(&data->img, data -> table, data -> cnt);

	mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, data -> img.mlx_img, 0, 0);

	return (0);
}


int draw(t_data data)
{
	//t_data	data;
	
	data.mlx_ptr = mlx_init();
	if(data.mlx_ptr == NULL)
		return(MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
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
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return(0);
}

int count_columns(char *name)
{
	int		ccnt;
	char	*line;
	int		fd;
	char	**the_line;
	
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	the_line = ft_split(line, 32);
	ccnt = count_col(the_line);
	int i = -1;
	while (the_line[++i + 1])
		continue ;
	if (the_line[i][0] == '\n')
		ccnt--;
	// I don't think that I should 
	return(ccnt);
}

int	main(int argc, char **argv)
{
	char	*name;
	t_tab	**table;
	t_lines	cnt;
	t_data data;
	//int ccnt;
	//what to connect
	cnt.ver_i = 0;
	cnt.hor_j = 0;
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
	/*************Part MLX ********************/
	draw(data);

}
