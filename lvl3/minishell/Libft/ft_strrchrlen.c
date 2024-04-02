/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:05:37 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/06 17:22:29 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchrlen(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
		i++;
	j = i;
	while (j >= 0)
	{
		if (s[j] == (char) c)
			return (j);
		else
			j--;
	}
	return (0);
}
