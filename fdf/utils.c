/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:44:03 by maria             #+#    #+#             */
/*   Updated: 2023/03/11 17:58:28 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_dup(char *src)
{
	int		i;
	char	*output;
	int		len;

	len = ft_strlen(src);
	i = 0;
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return (0);
	while (src[i])
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

void print(t_tab **table, int cnt)
{
	int i;
	int j;
	i = 0;
	while (i < cnt) 
	{
		j = 0;
    	while (j < cnt) 
		{
        // Print the x and y values for the current element
       		printf("(%d, %d), ", table[i][j].x, table[i][j].y);
       		j++;
		}
    	printf("\n");
    	i++;
    }
}