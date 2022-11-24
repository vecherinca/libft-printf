/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:54 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/24 23:33:01 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ischarset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	isfullcharset(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if (ischarset(s1[i], set))
			len++;
		i++;
	}
	return (len);
}

int	first_position(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!ischarset(s1[0], set))
			return (0);
		if (ischarset(s1[i], set) && (!ischarset(s1[i + 1], set)))
			return (i + 1);
		i++;
	}
	return (0);
}

int	second_position(char const *s1, char const *set)
{
	int	len;
	int	lentoreturn;

	lentoreturn = ft_strlen(s1);
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ischarset(s1[len], set) && (!ischarset(s1[len - 1], set)))
			return (len);
		len--;
	}
	return (lentoreturn);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_start;
	int		i;
	int		len_end;
	int		finallen;
	char	*output;

	if(!s1)
		return(NULL);
	i = 0;
	if (isfullcharset(s1, set) == ft_strlen(s1))
		return (ft_strdup(""));
	len_start = first_position(s1, set);
	len_end = second_position(s1, set);
	finallen = len_end - len_start + 1;
	output = malloc(sizeof(char) * (finallen));
	if(!output)
		return(NULL);
	output[finallen - 1] = '\0';
	while (i < finallen - 1)
	{
		output[i] = s1[len_start];
		i++;
		len_start++;
	}
	return (output);
}
