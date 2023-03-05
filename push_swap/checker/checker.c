/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:21:34 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 00:05:41 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/get_next_line.h"
#include "checker.h"

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
void parsethecommads(head_a *a, head_a *b, t_head_checker *start)
{
	t_checker *head;
	head = start -> first;

	while (head != NULL)
	{
		if (ft_strcmp(head -> content, "sa") == 0)
			sa(a);
		if (ft_strcmp(head -> content, "sb") == 0)
			sb(b);
		if (ft_strcmp(head -> content, "ss") == 0)
			ss(a, b);
		if (ft_strcmp(head -> content, "pa") == 0)
			pa(a, b);
		if (ft_strcmp(head -> content, "pb") == 0)
			pb(a, b);
		// if (ft_strcmp(head -> content, "ra") == 0)
		// 	ra(a);
		head = head -> next;
	}	
}
int	main(int argc, char **argv)
{
	t_checker	*head;
	t_head_checker 	*start;
	t_checker	*temp;
	head_a		*lista;
	head_a		*listb;
	char		*sstr;
	int 		value;

	lista = define_list_a(argc, argv);
	listb = define_list_b();
	check_the_stack(lista, listb);
	head = NULL;
	start = malloc(sizeof(t_head_checker));
	int i = 0;
	while (i < 3)
	{
		//sstr = get_next_line(0);
		temp = malloc(sizeof(t_checker));
		temp ->content = "ra";
		temp -> next = NULL;
		add_back_lst(&head, temp);
		i++;
	}
	start -> first = head;
	//printf("eheh ----->> %s", start ->first ->next->content);
	parsethecommads(lista, listb, start);
	t_checker *node;
	node = start -> first;
	while (node != NULL)
	{
		printf("NODE ---> %s\n", node -> content);
		node = node -> next;
		
	}
	print_the_list(lista);
}