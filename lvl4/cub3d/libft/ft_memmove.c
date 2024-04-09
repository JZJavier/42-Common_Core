/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:56:43 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 13:46:36 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	if (d < s)
		ft_memcpy (d, s, n);
	else
	{
		while (n > 0)
		{
			n --;
			d[n] = s[n];
		}
	}
	return (dest);
}

/*
int	main(void)
{
	char	test[] = "this is a long test for this project!";
	char	tag[100];
	char	tag2[100];

	printf ("this is the result 	 : %s \n", ft_memmove (tag, test, 50));
	printf ("this is the standard result : %s \n", memmove (tag2, test, 50));
	return 0;
}
*/