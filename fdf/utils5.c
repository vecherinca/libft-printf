/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:41:32 by mklimina          #+#    #+#             */
/*   Updated: 2023/05/29 22:11:18 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57) || (c == '+' || c == '-' || c == ' ' || c == '\n'))
		return (1);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
	{
			i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strstr_v2(char *str, char *to_find)
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
				return (str + i);
		}
		j = 0;
		i++;
	}
	return (0);
}

void	freee_tab_char_2(char **tab, t_lines cnt)
{
	int	index;

	index = cnt.hor_j;
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
}

// void	freee_tab_char_3(char **tab, int cnt)
// {
// 	int	index;

// 	index = cnt;
// 	while (index >= 0)
// 	{
// 		free(tab[index]);
// 		index--;
// 	}
// 	free(tab);
// }

void	freee_tab_(t_tab **tab, int cnt)
{
	int	index;

	index = cnt;
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
	free(tab);
}
