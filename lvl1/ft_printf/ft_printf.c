/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:24:27 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/21 13:16:06 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversions(va_list arg, const char *s, int *i)
{
	void	*ptr;

	if (s[0] == 'c')
		ft_putchar(va_arg(arg, int), i);
	if (s[0] == 's')
		ft_putstr(va_arg(arg, char *), i);
	if (s[0] == 'p')
	{
		ptr = va_arg(arg, void *);
		if (ptr)
			return (ft_ptr(ptr, i));
		return (ft_putstr("0x0", i));
	}
	if (s[0] == 'd' || s[0] == 'i')
		ft_putnbr(va_arg(arg, int), i);
	if (s[0] == 'u')
		ft_un_putnbr(va_arg(arg, unsigned int), i);
	if (s[0] == 'x')
		ft_low_hexa(va_arg(arg, unsigned long), i);
	if (s[0] == 'X')
		ft_hexa(va_arg(arg, unsigned long), i);
	if (s[0] == '%')
		ft_putchar('%', i);
}

int	ft_printf(const char *str, ...)
{
	va_list	varadic;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(varadic, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_conversions(varadic, str + i, &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(varadic);
	return (len);
}

/*int main(void)
{
	ft_printf("%c", '2');
	ft_printf("%s", (char *) NULL);
	printf("%s", (char *) NULL);
	ft_printf("%p", -982);
	ft_printf("%i", -1234567890);
	ft_printf("%d", -1234567890);
	ft_printf("%u", 1234567890);
	ft_printf("%x", -16);
	ft_printf("%X", -16);
	ft_printf("%%", 1234567);
	return (0);
}*/
