/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:43:41 by maria             #+#    #+#             */
/*   Updated: 2022/10/27 18:46:02 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int i;
	i = 0;

	while (str[i])
		i++;
	return(i);	
}
char *ft_strdup(const char *src)
{
	int i;
	char *output;
	int len;
	len = ft_strlen(src);

	i = 0;
	output = malloc(sizeof(char) * len + 1);
	if (!output)
		return(0);
	while(src[i])
	{
		output[i] = src[i];
		i++;
	}
	output[i] = '\0';
	return(output);
}