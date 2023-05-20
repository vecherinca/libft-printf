/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:13:31 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/21 00:15:57 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	if (c == 0)
		return ((char *)s + len);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		while ((str[i + j] == to_find[j]) && to_find[j] != 0)
		{
			j++;
			if (to_find[j] == '\0')
				return (str + i + 2);
		}
		j = 0;
		i++;
	}
	return (0);
}

float	find_min(t_tab **t, t_lines cnt)
{
	float	min;
	int		i;
	int		j;

	i = 0;
	min = 0;
	while (i < cnt.hor_j)
	{
		j = 0;
		while (j < cnt.ver_i)
		{
			if (t[i][j].z < min)
				min = t[i][j].z;
			j++;
		}
		i++;
	}
	return (min);
}

float	find_max(t_tab **t, t_lines cnt)
{
	float	max;
	int		i;
	int		j;

	i = 0;
	max = 0;
	while (i < cnt.hor_j)
	{
		j = 0;
		while (j < cnt.ver_i)
		{
			if (t[i][j].z > max)
				max = t[i][j].z;
			j++;
		}
		i++;
	}
	return (max);
}

float	find_z(t_tab **t, t_lines cnt)
{
	float	max;
	float	min;
	float	res;

	max = find_max(t, cnt);
	min = find_min(t, cnt);
	cnt.max = max;
	cnt.min = min;
	res = max - min;
	return ((res / 2) + min);
}
