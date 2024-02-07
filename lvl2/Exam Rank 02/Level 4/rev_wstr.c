/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@tudent.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:46:58 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 17:35:14 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (argc == 2)
	{
		while (argv[1][len])
			len++;
		while (argv[1][len] != ' ' || argv[1][len] == '\t')
			len--;
		while (argv[1][len + i + 1])
		{
			write (1, &argv[1][len + i + 1], 1);
			i++;
		}
		i = 0;
		if (len > 0)
			write (1, " ", 1);
		while (argv[1][i])
		{
			if (len > 0 && i < len)
			{
				write (1, &argv[1][i], 1);
				i++;
			}
			else
			{
				write (1, &argv[1][i], 1);
				i++;
			}

		}
	}
	write (1, "\n", 1);
	return (0);
}
