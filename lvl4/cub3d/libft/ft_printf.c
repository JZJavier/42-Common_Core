/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:54:35 by yugao             #+#    #+#             */
/*   Updated: 2024/01/21 02:04:36 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	size_t	arg_num;
	size_t	sum;

	sum = 0;
	arg_num = count_arg(str);
	va_start (arg, str);
	while (*str)
	{
		if (*str == '%' && is_c_legal (*(str + 1)) && arg_num != 0)
		{
			sum += asistant_print(is_c_legal(*(str + 1)), arg);
			str ++;
			arg_num --;
		}
		else
		{
			ft_putchar_fd (*str, 1);
			sum ++;
		}
		str ++;
	}
	va_end (arg);
	return (sum);
}

/*
int main(void)
{
	printf ("----ft_printf----: \n");
	ft_printf ("%s", (char *)NULL);
	printf ("------printf-----: \n");
	printf ("%s", (char *)NULL);
	printf ("----ft_printf----: \n");
	printf ("%d", ft_printf ("%s", (char *)NULL));
	printf ("------printf-----: \n");
	printf ("%d", printf ("%s", (char *)NULL));
	//ft_putstr_fd (NULL, 1);

	return 0;
}
*/