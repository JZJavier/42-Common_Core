/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asistant_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:35:17 by yugao             #+#    #+#             */
/*   Updated: 2024/01/21 02:07:22 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_putstr_count(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

static size_t	ft_putnbr_count(int n, int fd)
{
	size_t	len;

	ft_putnbr_fd (n, fd);
	len = 0;
	if (n < 0 || n == 0)
		len ++;
	while (n != 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

size_t	asistant_print(int type, va_list arg)
{
	size_t	count;

	count = 1;
	if (type == 1)
		ft_putchar_fd (va_arg (arg, int), 1);
	else if (type == 2)
		return (ft_putstr_count (va_arg(arg, char *)));
	else if (type == 3)
		return (ft_print_pointer(va_arg(arg, void *)));
	else if (type == 4)
		return (ft_putnbr_count (va_arg(arg, int), 1));
	else if (type == 6)
		return (ft_putinbr_fd (va_arg(arg, unsigned int), 1));
	else if (type == 7)
		return (dec_to_hex (va_arg (arg, unsigned int), 0));
	else if (type == 8)
		return (dec_to_hex (va_arg (arg, unsigned int), 1));
	else if (type == 9)
		ft_putchar_fd ('%', 1);
	return (count);
}

/*
int main (void)
{
	//int a = 1;
	printf ("==%zu==", ft_print_pointer (NULL));
	printf ("\n%p\n", NULL);
	printf ("%x = ", 1234);
	ft_printf ("%x\n", 1234);
	return 0;
}
*/