/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:05:37 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/13 07:56:15 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchrlen(const char *len, char c)
{
	int	i;

	i = 0;
	while (len[i] && len[i] != c)
		i++;
	if (len[i] != c)
		return (0);
	return (i);
}
