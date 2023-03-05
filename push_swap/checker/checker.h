/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:32:19 by maria             #+#    #+#             */
/*   Updated: 2023/03/04 18:01:53 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct a_list
{
	int				content;
	int				index;
	struct a_list	*next;
}a_list;

typedef struct head_a
{
	a_list	*first;
}head_a;

typedef struct checker
{
	char			*content;
	struct checker	*next;
}t_checker;

typedef struct checker_head
{
	t_checker *first;
}t_head_checker;

void	add_back_lst(t_checker **lst, t_checker *new);
void	print_the_list(head_a *head);
void parsethecommads(head_a *a, head_a *b, t_head_checker *start);
int		ft_strcmp(char *s1, char *s2);
void	free_list(a_list *head, head_a *main);
int		checkthearg(char *arg);
int		is_sorted(head_a *a);
int		ft_atoi(char *str);
int		check_the_stack(head_a *a, head_a *b);
a_list	*createlist(int argc, char **argv, head_a *point);
head_a	*define_list_a(int argc, char **argv);
head_a	*define_list_b(void);
char	*ft_itoa(int n);
int		ft_lstsize(a_list *lst);
void	ft_lstadd_back(a_list **lst, a_list *new);
a_list	*ft_lstlast(a_list *lst);
a_list	*findsecondlastnode(a_list *head);
int		check_doubl(head_a *heada);
void	pb(head_a *heada, head_a *headb);
void	pa(head_a *heada, head_a *headb);
void	ra(head_a *heada);
void	rb(head_a *headb);
void	rr(head_a *heada, head_a *headb);
void	rra(head_a *heada);
void	rrb(head_a *headb);
void	rrr(head_a *heada, head_a *headb);
void	sa(head_a *head);
void	sb(head_a *head);
void	ss(head_a *heada, head_a *headb);
#endif