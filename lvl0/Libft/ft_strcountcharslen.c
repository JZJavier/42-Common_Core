/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:05:37 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/14 16:50:28 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcountchars(const char *str, char c)
{
	int	i;
	int	ch;

	i = 0;
	ch = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ch++;
		i++;
	}
	return (ch);
}
