/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:49:30 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 17:47:02 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (*s == (unsigned char)c)
			return (s);
		i ++;
		s ++;
	}
	return (0);
}

/*
int	main(void)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	printf("%s\n", (char *) memchr(tab, -1, 7));
	printf("%s", (char *)ft_memchr(tab, -1, 7));
}
*/