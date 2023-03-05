/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mklimina <mklimina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:43:15 by mklimina          #+#    #+#             */
/*   Updated: 2023/03/05 19:45:40 by mklimina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_a_list
{
	int				content;
	int				index;
	struct t_a_list	*next;
}					t_a_list;

typedef struct t_head_a
{
	t_a_list		*first;
}					t_head_a;

typedef struct t_algo_values
{
	t_a_list		*node;
	int				rra;
	int				rrb;
	int				ra;
	int				rb;
	int				rr;
	int				rrr;

}					t_algo_values;

int					ft_atoi(char *str);
int					ft_isdigit(int c);
int					ft_lstsize(t_a_list *lst);
void				ft_lstadd_back(t_a_list **lst, t_a_list *new);
t_a_list			*ft_lstlast(t_a_list *lst);
t_a_list			*findsecondlastnode(t_a_list *head);
void				sa(t_head_a *head);
void				sb(t_head_a *head);
void				ss(t_head_a *heada, t_head_a *headb);
void				pb(t_head_a *heada, t_head_a *headb);
void				pa(t_head_a *heada, t_head_a *headb);
void				ra(t_head_a *heada, int flag);
void				rb(t_head_a *headb, int flag);
void				rr(t_head_a *heada, t_head_a *headb);
void				rrb(t_head_a *headb, int flag);
void				rrr(t_head_a *heada, t_head_a *headb);
void				rra(t_head_a *heada, int flag);
t_head_a			*define_list_b(void);
t_head_a			*define_list_a(int argc, char **argv);
int					checkthearg(char *arg);
int					check_the_stack(t_head_a *a, t_head_a *b);
int					ft_strlen(char *s);
int					check_doubl(t_head_a *heada);
int					ft_strcmp(char *s1, char *s2);
char				*ft_itoa(int n);
t_a_list			*find_max_nnode(t_a_list *start);
void				pushswap(t_head_a *a, t_head_a *b, int argc);
void				pushto_median(t_a_list *start, t_head_a *b, t_head_a *a,
						int median);
void				presort(int median, t_head_a *b, t_head_a *a);
t_algo_values		count_moves_a(t_a_list *node_a, t_head_a *a,
						t_algo_values current);
t_a_list			*get_nearest_max(t_a_list *b_node, t_head_a *a);
t_algo_values		number_moves(t_head_a *a, t_a_list *b_node, t_head_a *b,
						t_algo_values current);
int					calc_instructions(t_algo_values current,
						t_algo_values next_node);
void				assign_index(t_head_a *a);
void				sort3(t_head_a *a);
void				free_list(t_a_list *head, t_head_a *main);
void				sort5(t_head_a *a, t_head_a *b, int flag);
void				sort100(t_head_a *a, t_head_a *b);
void				movefastest(t_algo_values current, t_head_a *a,
						t_head_a *b);
t_a_list			*find_min(t_a_list *start);
void				pushmin(t_head_a *a, int min);
int					find_max(t_a_list *start);
int					find_min_next(t_a_list *start, int min);
t_a_list			*find_max_nnode(t_a_list *start);
#endif