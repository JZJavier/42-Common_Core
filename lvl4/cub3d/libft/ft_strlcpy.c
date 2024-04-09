/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:57:44 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 04:02:52 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i ++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen ((char *)src));
}

/*
int	main(void)
{
	char	test[100];
	char	test2[100];
	char	*dest, *dest2;
	int		a1,b;

	a1 = ft_strlcpy (dest2, "lorem ipsum dolor sit amet", 0);
	//b = strlcpy (dest2, "lorem ipsum dolor sit amet", 0);
	printf ("%s  %d\n", dest2, a1);
	printf ("%s  %d\n", dest, b);
}
*/