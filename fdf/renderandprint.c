/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderandprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:23:06 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/18 20:21:11 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x < 0 || x >= WINDOW_WIDTH) || (y < 0 || y >= WINDOW_HEIGHT))
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
