/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/04 00:23:26 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list	*create_list(int argc, char **argv, head_a *point)
{
	a_list	*temp;
	a_list	*head;
	int		i;

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
		temp = malloc(sizeof(a_list));
		if (!temp)
			return (NULL);
		temp->content = ft_atoi(argv[i]);
		temp->next = NULL;
		ft_lstadd_back(&head, temp);
		i++;
	}
	return (head);
}

head_a	*define_list_a(int argc, char **argv)
{
	head_a	*point;

	point = malloc(sizeof(head_a));
	if (!point)
		return (NULL);
	point->first = create_list(argc, argv, point);
	return (point);
}

head_a	*define_list_b(void)
{
	head_a	*point;
	a_list	*head;

	head = NULL;
	point = malloc(sizeof(a_list));
	point->first = head;
	return (point);
}

void	pushswap(head_a *a, head_a *b, int argc)
{
	int	number;

	number = argc - 1;
	if (number == 2)
		sa(a);
	if (number == 3)
		sort3(a);
	if (number == 4)
		sort5(a, b, 4);
	if (number == 5)
		sort5(a, b, 5);
	if (number > 5)
		sort100(a, b);
}

void	free_list(a_list *head, head_a *main)
{
	a_list	*current;
	a_list	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(main);
}

