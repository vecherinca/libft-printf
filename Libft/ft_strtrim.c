/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:55:54 by mklimina          #+#    #+#             */
/*   Updated: 2022/11/17 20:34:25 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

|||///Salut/Ca|Va|/,
et que je te dis de trim selon le charset
|/, tu dois me return
Salut/Ca|Va
tu dois enlever tous les charactere du charset au debut et a la fin mais pas au milieu

*/
//this one is checking if the certain char is in charset or not
int ischarset(char c, char const *set)
{
    int i;
    i = 0;

    while(set[i])
    {
        if (set[i] == c)
            return(1);
        i++;
    }
    if (c == '\0')
        return(1); // lol do we even need this?
    return(0);
}
// this thing is supposed to return first position from the beginning 
// let's suppose that it's working
// maybe we need +1 thing

int isfullcharset(char const *s1, char const *set)
{
	int i;
	int len;
    i = 0;
	len = 0;

    while(s1[i])
    {
        if (ischarset(s1[i], set))
            len++;
        i++;
    }
	return(len);	
}
int first_position(char const *s1, char const *set)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (ischarset(s1[i],set) && (!ischarset(s1[i+1], set)))
            return(i + 1);
        i++;
    }
    return(0);
}

int second_position(char const *s1, char const *set)
{
    int len;
    int lentoreturn;
    
    lentoreturn = ft_strlen(s1);
    len = ft_strlen(s1); 
    while (len > 0)
    {
        if(ischarset(s1[len], set) && (!ischarset(s1[len - 1], set)))
            return(len);
        len--;
    }
    return(lentoreturn);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int len_start;
    int i;
    int len_end;
    int finallen;
    char *output;

    i = 0; 
	if (isfullcharset(s1, set) == ft_strlen(s1))
		return(ft_strdup(""));
    len_start = first_position(s1,set);
    len_end = second_position(s1, set);
    finallen = len_end - len_start + 1;
    output = malloc(sizeof(char) * (finallen));
    output[finallen - 1] = '\0';
    while (i < finallen - 1)
    {
        output[i] = s1[len_start];
        i++;
        len_start++;    
    }
    return(output);
}

// int main()
// {
//   // char c[] = "//||Salut|\Cava//||";
//   // char set[] = "/|";
//   ft_strtrim("tripouille   xxx", " x");
// }

// int main()
// {
//   char c[] = "//||Salut|\Cava//||";
//   char set[] = "/|";
//   printf("%s",ft_strtrim(c,set));
// }