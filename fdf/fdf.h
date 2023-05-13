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

#define PI 3.14159265358979323846

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
	int		bpp;
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
	float hor_j;
	float ver_i;
	float max;
	float min;

}	t_lines;

typedef struct t_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_tab	**table;
	t_lines	cnt;
	int		move_y;
	int		move_x;
	float	zoom_factor;
	float	dezoom;
	int 	point64;
	int 	point32;
	float 	movez;
	float	alpha;
	float	beta;
	float	theta;
	float	central_x;
	float	central_y;
	float	central_z;


} t_data;

typedef struct t_cord
{
	float	x;
	float	y;
	float	z;

} t_cord;

char	**ft_split(char *s, char c);
void	print(t_tab **t, t_lines cnt);
int		ft_atoi(char *str);
int		count_col(char **tab);
t_lines	count_columns(char *name, t_lines cnt);
int		count_lines(char *name);
void	fill_tabtab(char **data, char *name);
void	fillfill(char **data, t_tab **table, t_lines cnt);
t_tab	**create_ttable(char *name, t_lines cnt);
int		powerof(int nb, int power);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchr(const char *s, int c);
int		hextoint(char *hex);
void	render_background(t_img *img, int color);
int		render(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_tab **table, t_lines cnt, t_data *data);
float	find_z(t_tab **t, t_lines cnt);
void	freee_tab_char(char **tab, t_lines cnt);
void	zoom_zoom(int keysym, t_data *data);
void	move_move(int keysym, t_data *data);
void	rotate_rotate(int keysym, t_data *data);
float	returnzoom(t_lines cnt);
void	freee_tab(t_tab **tab, t_lines cnt);
void	freee_tab_char(char **tab, t_lines cnt);
int		map_is_flipped(t_data *data);
int		draw(t_data data);
int		input_key(int keysym, t_data *data);
int		render(t_data *data);
int		render_reverse(t_img *img, t_tab **table, t_lines cnt, t_data *data);
int		render_rect(t_img *img, t_tab **table, t_lines cnt, t_data *data);
t_cord	zoom_and_rotate(float x, float y, float z, t_data *data);
void	bresenham(t_cord point2, t_cord point1, t_img *img, int color);
float	max(float x_step, float y_step);
float	mod(float num);
int		input_key(int keysym, t_data *data);
t_data	init(t_data data, t_lines cnt);
float	find_max(t_tab **t, t_lines cnt);
float	find_min(t_tab **t, t_lines cnt);
#endif