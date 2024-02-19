/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:33:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/10 17:19:35 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *) dest;
	i = 0;
	while (i < count)
	{
		a[i] = (unsigned char) c;
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
int	main (void)
{
	char pal [] = "Soy Pedrito";
	printf("%s", ft_memset (pal, '*', 4));
	return (0);
}*/
