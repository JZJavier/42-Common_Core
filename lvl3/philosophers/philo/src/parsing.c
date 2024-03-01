/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:42:09 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/29 22:46:09 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	args_validate(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (print_error("Negative arguments"));
		i++;
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) != 1)
				return (print_error("Argument not a number"));
			j++;
		}
		i++;
	}
	return (0);
}
