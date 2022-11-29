#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <stdarg.h>
int			ft_printf(const char *string, ...);
char    	ft_putnbr_fd(int nb);
int			ft_putstr_fd(char *s);
int			ft_putchar_fd(char c);
char		*ft_itoa(int n);
unsigned 	int	ft_putstr_unsign(char *s);
char	*ft_itoa_unsign(unsigned int n);
#endif