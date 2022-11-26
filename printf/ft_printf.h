#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdarg.h>
int		ft_printf(const char *string, ...);
void	ft_putnbr_fd(int n, int fd);
#endif