/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:26:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/14 06:38:34 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src [i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1 [] = "Paco";
	char str2 [] = "Pedro";
	printf("%zu", ft_strlcpy(str2, str1, sizeof(str2)));
	printf("%lu", strlcpy(str2, str1, sizeof(str2)));
	return(0);
}*/
