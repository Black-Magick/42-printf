/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:47:43 by remanuel          #+#    #+#             */
/*   Updated: 2022/11/24 16:05:06 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	n_flagcheck(va_list arguments, const char str, int *len)
{
	if (str == 'c')
		n_putchar((char)va_arg(arguments, int), len);
	else if (str == 's')
		n_putstr(va_arg(arguments, char *), len);
	else if (str == 'p')
		n_putadd(va_arg(arguments, void *), len);
	else if ((str == 'd') || (str == 'i'))
		n_putnbr(va_arg(arguments, int), len);
	else if (str == 'u')
		n_unsigned_nb(va_arg(arguments, unsigned int), len);
	else if (str == 'X')
		n_hexa(va_arg(arguments, size_t), str, len);
	else if (str == 'x')
		n_hexa(va_arg(arguments, size_t), str, len);
	else if (str == '%')
		n_putchar('%', len);
	else
		n_putchar((char)va_arg(arguments, int), len);
} 

int	ft_printf(const char *str, ...)
{
	va_list arguments;
	int		len;

	len = 0;
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			n_flagcheck(arguments, *str, &len);
		}
		else
			n_putchar(*str, &len);
		str++;
	}
	va_end(arguments);
	return (len);
}

/*int	main()
{
	//a = 13465456;
	//char *str = "PUTA!";
	ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %x %x %lx %lx %lx %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
}*/