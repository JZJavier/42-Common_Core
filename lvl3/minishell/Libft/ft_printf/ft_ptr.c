/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:03:19 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/14 06:38:34 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (len[i] != '\0')
		i++;
	return (i);
}

static void	rec_print(unsigned long n, const char *base, int *i)
{
	if (n > (unsigned long)(ft_strlen(base) - 1))
		rec_print(n / ft_strlen(base), base, i);
	ft_putchar(*(base + (n % ft_strlen(base))), i);
}

void	ft_ptr(void *format, int *i)
{
	unsigned long	n;
	const char		*base;

	n = (unsigned long)format;
	base = "0123456789abcdef";
	ft_putstr("0x", i);
	rec_print(n, base, i);
}
