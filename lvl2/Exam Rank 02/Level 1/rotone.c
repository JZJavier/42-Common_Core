/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:29:52 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/29 17:20:50 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 'A' && s[i] <= 'Y') || (s[i] >= 'a' && s[i] <= 'y'))
			ft_putchar(s[i] + 1);
		else if (s[i] == 'Z' || s[i] == 'z')
			ft_putchar(s[i] - 25);
		else
			ft_putchar(s[i]);
		++s;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	ft_putchar('\n');
	return (0);
}
