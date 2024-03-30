/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:58:50 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/30 21:00:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9'))
			i++;
		else
			return (FALSE);
	}
	if (i > 11)
		return (FALSE);
	return (TRUE);
}

int	parse(char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		if (is_num(argv[i]) == FALSE)
			return (printf("Error: Only numeric arguments allowed\n"), FALSE);
		num = ft_atol(argv[i]);
		if (num > INT_MAX)
			return (printf("Error: Value over INT MAX is not valid\n"), FALSE);
		if (num <= 0)
			return (printf("Error: Only numbers above 0 are valid\n"), FALSE);
		if (i == 1 && num > 200)
			return (printf("Error: 200 philos is the MAX\n"), FALSE);
		if ((i >= 2 && i <= 4) && num < 60)
			return (printf("Error: Values can't be lower than 60ms\n"), FALSE);
		i++;
	}
	return (TRUE);
}
