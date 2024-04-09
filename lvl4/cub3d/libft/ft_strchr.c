/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:57:15 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 18:42:08 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	c %= 256;
	if (c == '\0')
		return ((char *)&str[ft_strlen (str)]);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str ++;
	}
	return (0);
}

/*
int main (void)
{
	char test[] = "dddddthis is5 a test";
	
	printf ("re:%s\n", ft_strchr(test, '5'));
	printf ("re:%s\n", strchr(test, '5'));
}
*/