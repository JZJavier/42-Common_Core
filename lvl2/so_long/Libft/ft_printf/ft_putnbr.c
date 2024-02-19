/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:20:20 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/20 17:25:22 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", i);
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-', i);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		n %= 10;
	}
	if (n != -2147483648)
		ft_putchar(n + '0', i);
}

void	ft_un_putnbr(unsigned int n, int *i)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, i);
		n %= 10;
	}
	ft_putchar(n + '0', i);
}

/*int main(void)
{
	long long l = -1234567890;
	int i = 0;
	ft_putnbr(l, &i);
	return (0);
}*/
