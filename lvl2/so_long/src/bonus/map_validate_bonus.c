/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:25:52 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:12 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	map_parsing(char *filename)
{
	if (check_ber_extension_and_file(filename) == -1)
	{
		perror ("Error: file extension of the data isn't .ber");
		return (-1);
	}
	if (check_ber_extension_and_file(filename) == -2)
	{
		perror ("Error: data file doesn't exist on datas folder");
		return (-1);
	}
	if (check_invalid_characters(filename) == -1)
		return (-1);
	if (check_minimum_characters(filename) == -1)
		return (-1);
	if (check_rectangle(filename) == -1)
	{
		perror("Error: data isn't rectangle");
		return (-1);
	}
	if (check_line_len(filename) == -1)
	{
		perror("Error: data lines aren't same size ");
		return (-1);
	}
	return (0);
}

int	check_walls(char *filename)
{
	int		i;
	char	*map;

	i = 0;
	map = map_one_str(filename);
	while (map[i++] != '\0')
	{
		if (map[i] == '\n')
		{
			if (map[i - 1] != '1' && (map[i + 1] != '1' || map[i +1] != '\0'))
			{
				free(map);
				return (-1);
			}
		}
	}
	free(map);
	return (0);
}

int	check_floor_top(char *filename)
{
	int		i;
	char	*map;

	i = -1;
	map = map_one_str(filename);
	while (map[++i] != '\n')
	{
		if (map[i] != '1')
		{
			free(map);
			return (-1);
		}
	}
	while (map[i] != '\0')
		i++;
	while (map[--i] != '\n')
	{
		if (map[i] != '1')
		{
			free(map);
			return (-1);
		}
	}
	free(map);
	return (0);
}

int	map_validate(char *filename)
{
	if (map_parsing(filename) == -1)
		return (-1);
	if (check_walls(filename) == -1)
	{
		perror("Error: data wall's missing");
		return (-1);
	}
	if (check_floor_top(filename) == -1)
	{
		perror("Error: data floor or top is missing:");
		return (-1);
	}
	return (0);
}
