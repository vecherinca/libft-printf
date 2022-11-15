/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */  
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:31 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/15 16:21:33 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
checking if char is separator or not
*/
int ischr(char c, char cc)
{
	if (c == cc)
		return(1);
	else
		return(0);
}

/*
this function is working
okay and counting the number of 
words
params: s,c
*/
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
        if (!ischr(s[i], c))
            count++;
        while (!ischr(s[i], c) && s[i])
            i++;
    }

}
int len_word(char const *s, char c)
{
	int i;
	i = 0;
	while (s[i] != c)
	{
		i++;
	}
	return(i);
}
void fill_tab(char **tab, char const *s, char c)
{
	
}

char **ft_split(char const *s, char c)
{
	char **tab;
	int number_words;
	// first malloc is done, now I need to do the len of word and 2-nd malloc it
	number_words = numb_words(s,c);
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