/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:39:58 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/03 19:53:01 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_repeat(char c, int num)
{
	int i;

	i = 0;
	while (i <num)
	{
		write(1, &c, 1);
		i++;
	}
}
int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				write_repeat(argv[1][i], argv[1][i] + 1 - 'a');
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')	
				write_repeat(argv[1][i], argv[1][i] + 1 - 'A');
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
