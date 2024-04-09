/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:19:26 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/09 01:45:09 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_colors_f(t_parse *parse)
{
	char	*number;
	int		start;
	int		num;
	int		i;

	if (ft_strcountchars(parse->f, ',') != 2)
		return (perror("Error: countchars(,) != 2"), -1);
	i = 0;
	start = 0;
	while (parse->f[i])
	{
		if (ft_isnum(parse->f[i]) == 0)
			return (perror("Error: non numeric"), -1);
		if (parse->f[i] == ',' || parse->f[i + 1] == '\0')
		{
			number = ft_substr(parse->f, start, i + 1);
			num = ft_atoi(number);
			free(number);
			if (num < 0 || num > 255)
				return (perror("Error: num is not RGB valid"), -1);
			start = i + 1;
		}
		i++;
	}
	return (0);
}

int	check_colors_c(t_parse *parse)
{
	char	*number;
	int		start;
	int		num;
	int		i;

	if (ft_strcountchars(parse->c, ',') != 2)
		return (perror("Error: countchars(,) != 2"), -1);
	i = 0;
	start = 0;
	while (parse->c[i])
	{
		if (ft_isnum(parse->c[i]) == 0)
			return (perror("Error: non numeric"), -1);
		if (parse->c[i] == ',' || parse->c[i + 1] == '\0')
		{
			number = ft_substr(parse->c, start, i + 1);
			num = ft_atoi(number);
			free(number);
			if (num < 0 || num > 255)
				return (perror("Error: num is not RGB valid"), -1);
			start = i + 1;
		}
		i++;
	}
	return (0);
}
