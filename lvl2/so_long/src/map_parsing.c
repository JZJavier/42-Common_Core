/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:34:59 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/18 23:35:02 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ber_extension_and_file(char *filename)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(filename, '.');
	if (!(ft_strcmp(extension, ".ber") == 0))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-2);
	close (fd);
	return (0);
}

int	check_invalid_characters(char *filename)
{
	int		i;
	char	*map;

	i = 0;
	map = map_one_str(filename);
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'E' || map[i] == '\n')
			i++;
		else
		{
			free(map);
			perror("Error: data file contains invalid characters:");
			return (-1);
		}
	}
	free(map);
	return (0);
}

int	check_minimum_characters(char *filename)
{
	char	*map;
	int		check_e;
	int		check_c;
	int		check_p;

	map = map_one_str(filename);
	check_e = ft_strcountchars(map, 'E');
	check_c = ft_strcountchars(map, 'C');
	check_p = ft_strcountchars(map, 'P');
	if (check_e != 1 || check_c < 1 || check_p != 1)
	{
		free(map);
		perror("Error: data file doesn't contain valid amount of C, E, P:");
		return (-1);
	}
	free(map);
	return (0);
}

int	check_rectangle(char *filename)
{
	int		i;
	int		j;
	char	*map;
	int		nl;

	i = 0;
	j = 1;
	map = map_one_str(filename);
	nl = ft_strcountchars(map, '\n');
	while (map[i++] != '\0')
	{
		if (map[i] != '\n')
			j++;
		else
		{
			if (j <= nl)
			{
				free(map);
				return (-1);
			}
			j = 0;
		}
	}
	free(map);
	return (0);
}

int	check_line_len(char *filename)
{
	int		i;
	int		j;
	int		k;
	char	*map;

	i = 0;
	j = 1;
	map = map_one_str(filename);
	k = ft_strchrlen(map, '\n');
	while (map[i++] != '\0')
	{
		if (map[i] != '\n')
			j++;
		else
		{
			if (j != k)
			{
				free(map);
				return (-1);
			}
			j = 0;
		}
	}
	free(map);
	return (0);
}
