/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:28:21 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 14:44:44 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	if (a == 0 && b == 0)
		return (0);
	if (src > dst)
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	while (i < len)
	{
		a[len - 1] = b[len - 1];
		len--;
	}
	return (dst);
}

/*#include <stdio.h>
int main(void)
{
	char s[] = "Furbo:";
	char d[] = "Pppfpp";
	printf("%s", ft_memmove(((void *)0), ((void *)0), 5));
}*/
