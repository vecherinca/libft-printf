/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:32:19 by maria             #+#    #+#             */
/*   Updated: 2023/03/07 18:30:42 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct t_a_list
{
	int				content;
	int				index;
	struct t_a_list	*next;
}	t_a_list;

typedef struct t_head_a
{
	t_a_list	*first;
}	t_head_a;

typedef struct checker
{
	char			*content;
	struct checker	*next;
}	t_checker;

typedef struct checker_head
{
	t_checker	*first;
}	t_head_checker;
void		add_back_lst(t_checker **lst, t_checker *new);
void		parsethecommads(t_head_a *a, t_head_a *b, t_checker *start);
int			ft_strcmp(char *s1, char *s2);
void		free_list(t_a_list *head, t_head_a *main);
void		free_list_2(t_head_checker *main);
int			checkthearg(char *arg);
int			is_sorted(t_head_a *a);
int			ft_atoi(char *str);
int			check_the_stack(t_head_a *a, t_head_a *b);
t_a_list	*createlist(int argc, char **argv, t_head_a *point);
t_head_a	*define_list_a(int argc, char **argv);
t_head_a	*define_list_b(void);
char		*ft_itoa(int n);
int			ft_lstsize(t_a_list *lst);
void		ft_lstadd_back(t_a_list **lst, t_a_list *new);
t_a_list	*ft_lstlast(t_a_list *lst);
t_a_list	*findsecondlastnode(t_a_list *head);
int			check_doubl(t_head_a *heada);
char		*ft_strdup(const char *src);
/*INSTRUCTIONS*/
void		pb(t_head_a *heada, t_head_a *headb);
void		pa(t_head_a *heada, t_head_a *headb);
void		ra(t_head_a *heada);
void		rb(t_head_a *headb);
void		rr(t_head_a *heada, t_head_a *headb);
void		rra(t_head_a *heada);
void		rrb(t_head_a *headb);
void		rrr(t_head_a *heada, t_head_a *headb);
void		sa(t_head_a *head);
void		sb(t_head_a *head);
void		ss(t_head_a *heada, t_head_a *headb);
#endif