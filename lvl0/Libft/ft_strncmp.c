/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:55:18 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 19:23:42 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1 [i] || s2 [i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int main (void)
{
	char s1 [] = "PedroPedrito";
	char s2 [] = "Pedropuan";
	size_t n = 7;
	printf("%d", ft_strncmp(s1, s2, 6));
	return (0);
}*/
