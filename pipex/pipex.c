/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 20:36:15 by mklimina          #+#    #+#             */
/*   Updated: 2023/07/04 22:42:03 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
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

void	free_list(t_a_list *head, t_head_a *main)
{
	t_a_list	*current;
	t_a_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(main);
}

void	ft_lstadd_back(t_a_list **lst, t_a_list *new)
{
	t_a_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
t_a_list	*create_list(int argc, char **argv, t_head_a *point)
{
	t_a_list	*temp;
	t_a_list	*head;
	int			i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		// if (checkthearg(argv[i]) == 0)
		// {
		// 	write(2, "Error\n", 6);
		// 	free_list(head, point);
		// 	exit(0);
		// }
		point = point;
		temp = malloc(sizeof(t_a_list));
		if (!temp)
			return (NULL);
		temp->content = ft_strdup(argv[i]);
		temp->next = NULL;
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

t_head_a	*define_list_a(int argc, char **argv)
{
	t_head_a	*point;

	point = malloc(sizeof(t_head_a));
	if (!point)
		return (NULL);
	point->first = create_list(argc, argv, point);
	return (point);
}

void printLinkedList(t_a_list* start) {
    t_a_list* current = start;

    while (current != NULL) {
        printf("arg ---> %s\n", current->content);
        current = current->next;
    }
}
int	main(int argc, char **argv)
{
		// printf("number of the argc %d\n", argc);
		// printf("argv %s", argv[1]);
		
		t_head_a *list;
		list = define_list_a(argc, argv);
		list = list;
		t_a_list	*start;
		start = list -> first;
		printLinkedList(start);
		
}
