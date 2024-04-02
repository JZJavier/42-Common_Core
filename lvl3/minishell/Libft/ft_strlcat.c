/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <jjuarez-@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:37:52 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/14 06:38:34 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t		start;
	size_t		total;
	const char	*s;

	if ((!dest || !src) && !n)
		return (0);
	s = src;
	start = 0;
	while (*(dest + start) && start < n)
		start++;
	if (start < n)
		total = start + ft_strlen(s);
	else
		return (n + ft_strlen(s));
	while (*s && (start + 1) < n)
	{
		*(dest + start) = *s++;
		start++;
	}
	*(dest + start) = '\0';
	return (total);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "illodfhgjh";
	char str2[] = "calosfhdgjhkjhgsdhfg";
	//printf("Mia %zu\n", ft_strlcat(str1, str2, 50));
	//printf("Mia %s\n", str1);
	printf("Original %zu\n", strlcat(str1, str2, 4));
	printf("Original %s\n", str1);
	return (0);
}*/
