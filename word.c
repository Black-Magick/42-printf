/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remanuel <remanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:30:03 by remanuel          #+#    #+#             */
/*   Updated: 2022/11/24 12:39:31 by remanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	n_putstr(char *str, int *len)
{
	size_t	index;

	index = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	while (*str)
	{
		n_putchar(str[index], len);
		index++;
	}
}