/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:45:31 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/21 12:48:10 by jjuarez-         ###   ########.fr       */
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

void	ft_hexa(unsigned long n, int *i)
{
	char			*base;
	unsigned int	num;
	unsigned int	base_len;

	base = "0123456789ABCDEF";
	num = (unsigned int)n;
	base_len = ft_strlen(base);
	if (num > (base_len - 1))
		ft_hexa(num / base_len, i);
	ft_putchar(*(base + (num % base_len)), i);
}

void	ft_low_hexa(unsigned long n, int *i)
{
	char			*base;
	unsigned int	num;
	unsigned int	base_len;

	base = "0123456789abcdef";
	num = (unsigned int)n;
	base_len = ft_strlen(base);
	if (num > (base_len - 1))
		ft_low_hexa(num / base_len, i);
	ft_putchar(*(base + (num % base_len)), i);
}
