/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:50:03 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:56:43 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_duplicated(char *number, char **numbers, int len)
{
	int	i;

	i = 0;
	while (numbers[i] && i < len)
	{
		if (ft_strcmp(number, numbers[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_num(char *str)
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

char	**parse(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc < 2)
		exit (2);
	if (argc == 2 && !argv[1][0])
		exit (2);
	else if (argc == 2 && argv[1][0])
	{
		argv = ft_split(argv[1], ' ');
		i--;
	}
	while (argv[i])
	{
		if (is_num(argv[i]) == FALSE)
			print_error();
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			print_error();
		if (is_duplicated(argv[i], argv, i) == FALSE)
			print_error();
		i++;
	}
	return (argv);
}
