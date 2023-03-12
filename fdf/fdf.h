#ifndef FDF_H
# define FDF_H

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

# include "gnl/get_next_line.h"
# include "mlx_linux/mlx.h"

typedef struct s_tab
{
	int x;
	int y;
	int z;
	int color;
}	t_tab;

char	**ft_split(char *s, char c);
void	print(t_tab **table, int cnt);
int		ft_atoi(char *str);
int		count_col(char **tab);
int		count_lines(char *name);
void	fill_tabtab(char **data, char *name);
void	fillfill(char	**data, t_tab **table);
t_tab	**create_ttable(char *name);
int		powerof(int nb, int power);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchr(const char *s, int c);
int		hextoint(char *hex);
#endif