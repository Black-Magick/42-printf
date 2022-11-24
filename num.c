/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:51:12 by remanuel          #+#    #+#             */
/*   Updated: 2022/11/24 11:51:22 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_putnbr(int nb, int *len)
{
	if (nb == INT_MIN)
		n_putstr("-2147483648", len);
	else if (nb < 0)
	{
		n_putchar('-', len);
		nb = -nb;
		n_putnbr(nb, len);
	}
	else if (nb > 9)
	{
		n_putnbr((nb / 10), len);
		n_putnbr((nb % 10), len);
	}
	else
		n_putchar((nb + 48), len);
}

void	n_unsigned_nb(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		n_unsigned_nb((nb / 10), len);
		n_unsigned_nb((nb % 10), len);
	}
	else
		n_putchar((nb + 48), len);
}

void	n_hexa(size_t nb, char format, int *len)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb > 16)
	{
		n_hexa((nb / 16), format, len);
		n_hexa((nb % 16), format, len);
	}
	else
		n_putchar((base[nb % 16]), len);
}

void	n_putadd(void *add, int *len)
{
	size_t address;

	address = (size_t)add;
	if (address == 0)
	{
		n_putstr("(nil)", len);
		return ;
	}
	n_putstr("0x", len);
	n_hexa(address, 'x', len);
}