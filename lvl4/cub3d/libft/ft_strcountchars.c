/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:26:56 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/09 00:27:07 by jjuarez-         ###   ########.fr       */
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
