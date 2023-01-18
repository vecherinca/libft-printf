
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include<stdlib.h>
#include<stdio.h>

typedef struct a_list
{
	int			content;
	struct a_list	*next;
}a_list;

typedef struct head_a
{
	a_list *first;
}head_a;

int	ft_atoi(const char *str);
int	ft_lstsize(a_list *lst);
void sa(a_list *head);
#endif