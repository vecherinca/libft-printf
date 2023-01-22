
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
a_list	*ft_lstlast(a_list *lst);
a_list	*findsecondlastnode(a_list *head);
void	sa(head_a *head);
void	sb(head_a *head);
void	ss(head_a *heada, head_a *headb);
void	pb(head_a *heada, head_a *headb);
void	pa(head_a *heada, head_a *headb);
void	ra(head_a *heada);
void	rb(head_a *headb);
void 	rr(head_a *heada, head_a *headb);
void	rrb(head_a *headb);
void	rrr(head_a *heada, head_a *headb);
void 	rra(head_a *heada);
int		ft_isdigit(int c);
int		checkthearg(char *arg);
int		ft_strlen(const char *s);
int		check_doubl(head_a *heada);

#endif