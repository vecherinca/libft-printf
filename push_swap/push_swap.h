
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
	int				content;
	int				index;
	int 			next_biggest;
	struct a_list	*next;
}a_list;

typedef struct head_a
{
	a_list *first;
}head_a;

typedef struct algo_values
{
	a_list *node;
	int rra;
	int rrb;
	int ra;
	int rb;

}algo_values;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);

int		ft_lstsize(a_list *lst);
void	ft_lstadd_back(a_list **lst, a_list *new);
a_list	*ft_lstlast(a_list *lst);
a_list	*findsecondlastnode(a_list *head);

void	sa(head_a *head);
void	sb(head_a *head);
void	ss(head_a *heada, head_a *headb);
void	pb(head_a *heada, head_a *headb);
void	pa(head_a *heada, head_a *headb);
void	ra(head_a *heada, int flag);
void	rb(head_a *headb, int flag);
void 	rr(head_a *heada, head_a *headb);
void	rrb(head_a *headb, int flag);
void	rrr(head_a *heada, head_a *headb);
void 	rra(head_a *heada, int flag);

int		checkthearg(char *arg);
int		ft_strlen(char *s);
int		check_doubl(head_a *heada);
int		properint(char *arg);

void	print_the_list(head_a *head);
void	print_side_by_side(head_a *head);
void	print_index(head_a *head);

void	pushswap(head_a *a, head_a *b, int argc);

//void	check_sort(head_a *heada);
void	assign_index(head_a *a);
void	sort3(head_a *a);
void	sort5(head_a *a, head_a *b);
void	sort100(head_a *a,head_a *b);
void	algo(head_a *a, head_a *b);
void movefastest(algo_values current, head_a *a, head_a *b);
a_list	*find_min(a_list *start);
void	pushmin(head_a *a, int min);
int		find_max(a_list *start);
int		find_min_next(a_list *start, int min);
a_list *find_max_nnode(a_list *start);

#endif