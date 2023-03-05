/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:33:36 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 20:09:31 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_a_list	*create_list(int argc, char **argv, t_head_a *point)
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
	point->first = create_list(argc, argv, point);
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

void	pushswap(t_head_a *a, t_head_a *b, int argc)
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
