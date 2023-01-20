
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct a_list
{
	int			content;
	struct a_list	*next;
}a_list;

typedef struct head_a
{
	a_list *first;
}head_a;

int		ft_atoi(const char *str);
int		ft_lstsize(a_list *lst);
void	ft_lstdelone(a_list *lst, void (del)(int));
void	ft_lstadd_back(a_list **lst, a_list *new);
void	sa(head_a *head);
void	sb(a_list *head);
void	ss(a_list *head_a, a_list *head_b);
void	pb(a_list *head_a, a_list *head_b);
#endif