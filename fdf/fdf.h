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
#include <X11/X.h>
# include "gnl/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <X11/keysym.h>
#include <math.h>
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLACK_PIXEL 0x000000

typedef struct t_tab
{
	int x;
	int y;
	int z;
	int color;
}	t_tab;

typedef struct t_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;


typedef struct t_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;

}	t_rect;

typedef struct t_lines
{
	int hor_j;
	int ver_i;

}	t_lines;

typedef struct t_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_tab	**table;
	t_lines cnt;
	int		move_y;
	int		move_x;
	float	dezoom;
	float	rot;
	int 	point64;
	int 	point32;
	int 	movez;

} t_data;

typedef struct t_cord
{
	float	x;
	float	y;
	float	x1;
	float	y1;

} t_cord;

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
void	render_background(t_img *img, int color);
int		render(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_tab **table, t_lines cnt, t_data *data);

#endif