/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 07:19:10 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 07:45:37 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int duplicate(char c, char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            j = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j] && !duplicate(argv[1][i], argv[1], i))
                {
                    write(1, &argv[1][i], 1);
                    break;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
