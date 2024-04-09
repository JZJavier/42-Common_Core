/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:33:43 by yugao             #+#    #+#             */
/*   Updated: 2024/01/21 02:04:32 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	d_to_hex(unsigned int num, int is_mayuscura, size_t *len)
{
	if (num == 0)
		return ;
	if (num % 16 < 10)
	{
		d_to_hex (num / 16, is_mayuscura, len);
		ft_putnbr_fd (num % 16, 1);
	}
	else
	{
		if (is_mayuscura == 1)
		{
			d_to_hex (num / 16, is_mayuscura, len);
			ft_putchar_fd ('A' + num % 16 - 10, 1);
		}
		else
		{
			d_to_hex (num / 16, is_mayuscura, len);
			ft_putchar_fd ('a' + num % 16 - 10, 1);
		}
	}
	*len += 1;
}

static void	p_dec_to_hex(uintptr_t num, int big, size_t *len, size_t wid)
{
	if (num == 0 && wid >= 1)
		return ;
	if (wid > 1 || num >= 16)
		p_dec_to_hex (num / 16, big, len, wid - 1);
	if (num % 16 < 10)
		ft_putnbr_fd (num % 16, 1);
	else
	{
		if (big == 1)
			ft_putchar_fd ('A' + num % 16 - 10, 1);
		else
			ft_putchar_fd ('a' + num % 16 - 10, 1);
	}
	(*len)++;
}

size_t	ft_print_pointer(void *ptr)
{
	size_t		len;
	uintptr_t	ptr_val;

	len = 0;
	ptr_val = (uintptr_t) ptr;
	write(1, "0x", 2);
	len = 2;
	if (ptr)
		p_dec_to_hex(ptr_val, 0, &len, sizeof(uintptr_t) * 2);
	else
	{
		len ++;
		ft_putchar_fd ('0', 1);
	}
	return (len);
}

size_t	dec_to_hex(unsigned int num, int is_mayuscura)
{
	size_t	len;

	len = 0;
	if (num)
		d_to_hex (num, is_mayuscura, &len);
	else
	{
		len ++;
		ft_putchar_fd ('0', 1);
	}
	return (len);
}

/*
int main (void)
{
	
	printf("%d\n", printf ("%x", 12345678));
	return 0;
}
*/