/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:19:06 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 19:48:06 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*a;

	a = (const char *) s;
	i = 0;
	while (i < n)
	{
		if (a[i] == (char) c)
			return ((void *) &a[i]);
		else
			i++;
	}
	return (0);
}

/*#include <stdio.h>
int main (void)
{
	char ar [] = "aaaabaaaabaaaaa b aa dab";
	int ch = '\0';
	printf("%s", ft_memchr(ar, ch, 6));
	return (0);
}*/
