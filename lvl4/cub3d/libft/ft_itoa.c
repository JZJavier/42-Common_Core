/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:40:37 by yugao             #+#    #+#             */
/*   Updated: 2024/01/11 18:41:05 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	rev_num(long n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	count_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*fin;
	int		len;

	len = count_len (n);
	if (n < 0)
		len ++;
	fin = (char *) malloc (sizeof (char) * (len + 1));
	if (!fin)
		return (0);
	fin[len] = '\0';
	if (n == 0)
	{
		fin[0] = '0';
		return (fin);
	}
	while (n != 0)
	{
		fin[len - 1] = rev_num (n % 10) + '0';
		len --;
		n = rev_num (n / 10);
	}
	if (len - 1 == 0)
		fin[len - 1] = '-';
	return (fin);
}

/*
int main ()
{
	char	*test;
	test = ft_itoa (-32423423);
	printf ("%s\n", test);
	return 0;
}
*/
