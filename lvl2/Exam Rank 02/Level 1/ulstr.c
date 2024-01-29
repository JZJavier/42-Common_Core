/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:23:56 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/29 18:31:26 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ulstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			ft_putchar(s[i] - 32);
		else if (s[i] >= 'A' && s[i] <= 'Z')
			ft_putchar(s[i] + 32);
		else
			ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
		ulstr(argv[1]);
	ft_putchar('\n');
	return (0);
}
