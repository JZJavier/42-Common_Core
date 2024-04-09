/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:58:16 by yugao             #+#    #+#             */
/*   Updated: 2024/02/22 00:57:32 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	p1;
	size_t	p2;

	p1 = 0;
	p2 = 0;
	if (needle[p1] == 0)
		return ((char *)haystack);
	while (haystack[p1] && p1 < len)
	{
		while (haystack[p1 + p2] && needle[p2] == haystack[p1 + p2]
			&& p1 + p2 < len)
		{
			p2 ++;
			if (needle[p2] == 0 && haystack[p1 + p2] == 0)
				return ((char *)(haystack + p1));
		}
		p1 ++;
		p2 = 0;
	}
	return (0);
}

/*
int main(void)
{
	char str1[] = "9";
	char str2[] = "9";

	printf ("r1:%s\n", ft_strnstr(str1, str2, 1));
	printf ("r2:%s\n", strnstr(str1, str2, 1));
}
*/