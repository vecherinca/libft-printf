/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:21:34 by maria             #+#    #+#             */
/*   Updated: 2023/03/05 21:53:07 by mklimina         ###   ########.fr       */
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
void parsethecommads(t_head_a *a, t_head_a *b, t_head_checker *start)
{
	t_checker *head;
	head = start -> first;
	printf("eheh ----->> %s", start ->first ->content);
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
		if (ft_strcmp(head -> content, "ra\n") == 0)
			ra(a);
		head = head -> next;
	}	
}
int	main(int argc, char **argv)
{
	t_checker		*head;
	t_head_checker	*start;
	t_checker		*temp;
	t_head_a		*lista;
	t_head_a		*listb;
	char			*sstr;
	int				value;
	int				len;

	lista = define_list_a(argc, argv);
	listb = define_list_b();
	check_the_stack(lista, listb);
	head = NULL;
	start = malloc(sizeof(t_head_checker));
	int i = 0;
	sstr = malloc(sizeof(char) *4);
	while (sstr != NULL)
	{
		sstr = get_next_line(0);
		if (!sstr)
			break ;
		// if (!ft_strcmp("null\n", sstr))
		// 	break ;
		printf("SSTR ----> %s", sstr);
		temp = malloc(sizeof(t_checker));
		temp ->content = malloc(sizeof(char) * 4); //? on est pas sur :(
		temp -> content = sstr; //this one is not ok
		temp -> next = NULL;
		add_back_lst(&head, temp);
	}
	start -> first = head;
	parsethecommads(lista, listb, start);
	t_checker *node;
	node = start -> first;
	// while (node != NULL)
	// {
	// 	printf("NODE ---> %s\n", node -> content);
	// 	node = node -> next;
		
	// }
	print_the_list(lista);
}