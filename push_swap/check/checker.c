/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:21:34 by maria             #+#    #+#             */
/*   Updated: 2023/03/07 19:23:02 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "gnl/get_next_line.h"

void	add_back_lst(t_checker **lst, t_checker *new)
{
	t_checker	*tmp;

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

void	parsethecommads(t_head_a *a, t_head_a *b, t_checker *head)
{
	while (head != NULL)
	{
		if (ft_strcmp(head->content, "sa\n") == 0)
			sa(a);
		if (ft_strcmp(head->content, "sb\n") == 0)
			sb(b);
		if (ft_strcmp(head->content, "pa\n") == 0)
			pa(a, b);
		if (ft_strcmp(head->content, "pb\n") == 0)
			pb(a, b);
		if (ft_strcmp(head->content, "ra\n") == 0)
			ra(a);
		if (ft_strcmp(head->content, "rb\n") == 0)
			rb(b);
		if (ft_strcmp(head->content, "rr\n") == 0)
			rr(a, b);
		if (ft_strcmp(head->content, "rra\n") == 0)
			rra(a);
		if (ft_strcmp(head->content, "rrb\n") == 0)
			rrb(b);
		if (ft_strcmp(head->content, "rrr\n") == 0)
			rrr(a, b);
		head = head->next;
	}
}

t_checker	*return_head(void)
{
	t_checker		*head;
	t_checker		*temp;
	char			*sstr;

	head = NULL;
	while (1)
	{
		sstr = get_next_line(0);
		if (!sstr)
			break ;
		if (checksstr(sstr) == 0)
			error();
		temp = malloc(sizeof(t_checker));
		if (!temp)
			return (NULL);
		temp->content = ft_strdup(sstr);
		if (!temp -> content)
			return (NULL);
		temp->next = NULL;
		add_back_lst(&head, temp);
		free(sstr);
	}
	return (head);
}

t_head_checker	*init_the_inst(void)
{
	t_checker		*head;
	t_head_checker	*start;

	start = malloc(sizeof(t_head_checker));
	if (!start)
		return (NULL);
	head = return_head();
	if (!head)
		return (NULL);
	start->first = head;
	return (start);
}

int	main(int argc, char **argv)
{
	t_head_checker	*start_node;
	t_head_a		*lista;
	t_head_a		*listb;

	if (argc == 1)
		write(1, "Checker needs some arguments!", 30);
	if (argc < 2)
		exit(0);
	lista = define_list_a(argc, argv);
	listb = define_list_b();
	if (!lista || !listb)
		return (0);
	check_the_stack(lista, listb);
	start_node = init_the_inst();
	if (!start_node)
		return (0);
	parsethecommads(lista, listb, start_node->first);
	if (is_sorted(lista) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(lista->first, lista);
	free_list(listb->first, listb);
	free_list_2(start_node);
}
