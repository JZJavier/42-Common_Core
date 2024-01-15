/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:47:47 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 14:06:24 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	if (b == 0 && a == 0 && n > 0)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

/*#include <stdio.h>
int main(void)
{
	char s [] = "Javier";
	char d [] = "Juannn";
	printf("%s", ft_memcpy(((void *)0), ((void *)0), 0));
	return (0);
}*/
