#include "ft_printf.h"

void	n_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	n_putstr(char *str, int *len)
{
	size_t	index;

	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		index = 0;
		while (str[index])
			n_putchar(str[index++], len);
	}
}
