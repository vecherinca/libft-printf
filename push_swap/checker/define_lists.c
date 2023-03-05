/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 23:39:28 by maria             #+#    #+#             */
/*   Updated: 2023/03/04 15:54:06 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
	{
			i++;
	}
	return (s1[i] - s2[i]);
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

int	checkthearg(char *arg)
{
	char	*test;

	test = ft_itoa(ft_atoi(arg));
	if (ft_strcmp(test, arg) != 0)
		return (free(test), 0);
	return (free(test), 1);
}

int	is_sorted(head_a *a)
{
	a_list	*starta;

	starta = a->first;
	while (starta->next != NULL)
	{
		if (starta->content > starta->next->content
			&& (starta->content != starta->next->content))
			return (0);
		starta = starta->next;
	}
	return (1);
}

int ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1 * sign;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	check_the_stack(head_a *a, head_a *b)
{
	int	check;

	check = check_doubl(a);
	if (check == 0)
	{
		write(2, "Error\n", 6);
		free_list(a-> first, a);
		free_list(b-> first, b);
		exit(0);
	}
	if (is_sorted(a) == 1)
	{
		free_list(a-> first, a);
		free_list(b-> first, b);
		exit(0);
	}
	return (1);
}

a_list	*createlist(int argc, char **argv, head_a *point)
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
	point->first = createlist(argc, argv, point);
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