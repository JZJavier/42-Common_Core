/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:20:47 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 15:47:37 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int get_digit(char c, int digits_in_base)
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}
