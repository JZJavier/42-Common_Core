/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:48:47 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 15:02:47 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = argv[1][i] + 32;
		 if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') && (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\t' || argv[1][i + 1] == '\0'))
			 argv[1][i] = argv[1][i] - 32;
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
