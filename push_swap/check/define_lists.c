/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:39:28 by maria             #+#    #+#             */
/*   Updated: 2023/03/06 20:16:02 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

t_a_list	*createlist(int argc, char **argv, t_head_a *point)
{
	t_a_list	*temp;
	t_a_list	*head;
	int			i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		if (checkthearg(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			free_list(head, point);
			exit(0);
		}
		temp = malloc(sizeof(t_a_list));
		if (!temp)
			return (NULL);
		temp->content = ft_atoi(argv[i]);
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
	point->first = createlist(argc, argv, point);
	return (point);
}

t_head_a	*define_list_b(void)
{
	t_head_a	*point;
	t_a_list	*head;

	head = NULL;
	point = malloc(sizeof(t_a_list));
	if (!point)
		return (NULL);
	point->first = head;
	return (point);
}
