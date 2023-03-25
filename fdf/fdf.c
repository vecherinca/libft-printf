/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:17:32 by maria             #+#    #+#             */
/*   Updated: 2023/03/25 19:24:33 by mklimina         ###   ########.fr       */
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

int	render(t_data *data)
{
	/* if window has been destroyed, we don't want to put the pixel ! */
	if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}
int	main(int argc, char **argv)
{
	char	*name;
	t_tab	**table;
	t_data	data;
	//int		cnt;
	//void	*mlx_win;
	(void)argc;
	name = argv[1];
	//cnt = count_lines(name);
	table = create_ttable(name);
	table = table;
	// // print(table, cnt);

	/*************Part MLX ********************/

	/*1. Try to open and close the window*/

	data.mlx_ptr = mlx_init();
	if(data.mlx_ptr == NULL)
		return(MLX_ERROR);
	
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	
	/*HOOKS*/
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &input_key, &data);
	// mlx_loop(data.mlx_ptr);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);

}
