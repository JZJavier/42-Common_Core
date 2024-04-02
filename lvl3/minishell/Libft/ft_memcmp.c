/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:33:12 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/14 18:03:24 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*a;
	const char	*b;
	size_t		i;

	a = (const char *) s1;
	b = (const char *) s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return ((unsigned char) a[i] - (unsigned char) b[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	const char s1 [] = "Javieiiiiiii";
	const char s2 [] = "Javieiiiiiiii";
	printf("%d", ft_memcmp(s1, s2, 7));
	return (0);
}*/
