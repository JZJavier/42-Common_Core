/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:34:43 by yugao             #+#    #+#             */
/*   Updated: 2024/01/20 04:32:36 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_arg(const char *str)
{
	size_t	num;

	num = 0;
	while (*str)
	{
		if (*str == '%' && is_c_legal(*(str + 1)))
			num ++;
		str ++;
	}
	return (num);
}
