/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:19:16 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/21 13:16:52 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_conversions(va_list arg, const char *s, int *i);
void	ft_putchar(int c, int *i);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *i);
void	ft_un_putnbr(unsigned int n, int *i);
void	ft_putchar_per(int c, int *i);
void	ft_hexa(unsigned long n, int *i);
void	ft_low_hexa(unsigned long n, int *i);
void	ft_ptr(void *format, int *i);

#endif
