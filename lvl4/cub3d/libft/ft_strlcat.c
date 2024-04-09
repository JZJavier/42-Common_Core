/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:21:02 by yugao             #+#    #+#             */
/*   Updated: 2023/11/23 13:43:24 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	len;

	len = 0;
	index = 0;
	while (dest[len] != '\0')
		len ++;
	while (src[index] != '\0' && len + 1 < size)
	{
		dest[len] = src[index];
		index ++;
		len ++;
	}
	dest[len] = '\0';
	if (len > size)
		len = size;
	while (src[index] != '\0')
	{
		index ++;
		len ++;
	}
	return (len);
}

/*
int main ()
{
	char test[100]  = "hola";
	char test1[100]  = "hola";
	char target[100] = "nihao";
	printf ("%d  :%s \n", ft_strlcat (test, target, 2), test);
	printf ("%lu  :%s \n", strlcat (test1, target, 2), test1);
}*/