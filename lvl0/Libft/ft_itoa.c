/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:36:16 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/15 11:56:37 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "libft.h"

static size_t	count(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	long	num;

	num = n;
	size = count(n);
	if (n < 0)
	{
		num *= -1;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	*(str + size) = 0;
	while (size--)
	{
		*(str + size) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}

/*#include <stdio.h>
int main(void)
{
	int n = -2147483648;
	printf("%s", ft_itoa(n));
	return (0);
}*/
