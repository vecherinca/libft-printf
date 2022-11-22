/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:31 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/22 19:16:01 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
fix the free thing please
*/
int ischr(char c, char cc)
{
	if (c == cc)
		return (1);
	else
		return (0);
}

int numb_words(char const *s, char c)
{
	int i;
	int count;
	i = 0;
	count = 0;
	while (s[i])
	{
		while (ischr(s[i], c))
			i++;
		if (!ischr(s[i], c) && s[i] != '\0')
			count++;
		while (!ischr(s[i], c) && s[i])
			i++;
	}
	return (count);
}

void create_tab(char **tab, char const *s, char c)
{
	int i;
	int index;
	int len;

	i = 0;
	index = 0;
	len = 0;
	while (i < ft_strlen(s))
	{
		while (ischr(s[i], c) && s[i] && s[i] != '\0')
			i++;
		while (!(ischr(s[i], c)) && s[i])
		{
			len++;
			i++;
		}
		tab[index] = malloc(sizeof(char) * len + 1);
		if (!tab[index])
			return ;
		tab[index][len] = '\0';
		i++;
		index++;
		len = 0;
	}
}

void fill_tab(char **tab, char const *s, char c)
{
	int i;
	int j;
	int index;

	i = 0;
	index = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		while (ischr(s[i], c) && s[i] && s[i] != '\0')
			i++;
		while (!(ischr(s[i], c)) && s[i])
		{
			tab[index][j] = s[i];
			j++;
			i++;
		}
		index++;
		i++;
		j = 0;
	}
}

char **ft_split(char const *s, char c)
{
	char **tab;
	int number_words;
	// first malloc is done, now I need to do the len of word and 2-nd malloc it
	number_words = numb_words(s, c);
	if (number_words == 0)
		return(ft_calloc(1, sizeof(char *)));
	tab = malloc(sizeof(char *) * (number_words + 1));
	if (!tab)
		return (0);
	create_tab(tab, s, c);
	fill_tab(tab, s, c);
	tab[number_words] = 0;
	return (tab);
}
