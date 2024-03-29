#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

void	n_putchar(char c, int *len);
void	n_putstr(char *str, int *len);
void	n_putnbr(int nb, int *len);
void	n_unsigned_nb(unsigned int nb, int *len);
void	n_putadd(const void *add, int *len);
void	n_hexa(unsigned int nb, char format, int *len);
int		ft_printf(const char *str, ...);

#endif