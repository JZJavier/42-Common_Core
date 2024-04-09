/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:32:39 by yugao             #+#    #+#             */
/*   Updated: 2024/01/20 23:32:34 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putinbr_count(unsigned int n, int fd, size_t *len)
{
	char	num;

	if (n < 10)
	{
		num = n + '0';
		write (fd, &num, fd);
		*len += 1;
	}
	else
	{
		ft_putinbr_count (n / 10, fd, len);
		ft_putinbr_count (n % 10, fd, len);
	}
}

size_t	ft_putinbr_fd(unsigned int n, int fd)
{
	size_t	len;

	len = 0;
	ft_putinbr_count (n, fd, &len);
	return (len);
}

/*
int main(void)
{
	printf ("%zu", ft_putinbr_fd(0, 1));
	return 0;
}
*/