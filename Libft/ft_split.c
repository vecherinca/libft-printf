/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:31 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/14 19:15:02 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// working fine
int ft_sep(char c, char sep)
{
	if ((c == sep))
		return (1);
	else
		return (0);
}
int numb_words(char const *s, char c)
{
	int i;
	int num_words;

	num_words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_sep(s[i], c) && (!ft_sep(s[i + 1], c))) // this might not be okay
			num_words++;
		i++;
	}
	return (num_words);
}
int lenword(char const *s, char c)
{
	int i;

	i = 0;
	// can make a func here
	while (s[i] != c)
	{
		i++;
	}
	return (i);
}
void fill_tab(char **tab, char const *s, char c)
{
	int i;
	int j;
	int index;
	int len;

	i = 0;
	j = 0;
	len = 0;
	index = 0;
	while (s[i] != 0)
	{
		if (!(ft_sep(s[i], c)))
		{
			i++;
			len++;
		}
		tab[index] = malloc(sizeof(char) * len + 1);
		tab[index][len] = 0;
		index++;
		len = 0;
	}
}

char **ft_split(char const *s, char c)
{
	char **tab;
	int number_words;
	// first malloc is done, now I need to do the len of word and 2-nd malloc it
	number_words = numb_words(s);
	tab = malloc(sizeof(char *) * (number_words + 1));
	tab[number_words] = 0;
	fill_tab(tab, s, c);
}

int main()
{
	char test[] = "I-love-Turells-chips";
	char c;
	c = 45;
	ft_split(test, c);
}