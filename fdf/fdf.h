#ifndef FDF_H
# define FDF_H

# include "gnl/get_next_line.h"

typedef struct s_tab
{
	int x;
	int y;
	int z;
	int color;
}	t_tab;
char	**ft_split(char *s, char c);
#endif