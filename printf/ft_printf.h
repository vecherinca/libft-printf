#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <stdarg.h>
int		ft_printf(const char *string, ...);
int		ft_putnbr_fd(int n);
int		ft_putstr_fd(char *s);
int		ft_putchar_fd(char c);
#endif