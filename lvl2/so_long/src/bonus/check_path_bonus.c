/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:00:47 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 00:38:49 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_path(t_map *map, int y, int x)
{
	char	*p;

	p = &map->matrice_copy[y][x];
	if (*p != '1')
	{
		if (*p == 'C')
			map->collectible_copy--;
		*p = '1';
		if (map->matrice_copy[y][x + 1] != '1')
			check_path(map, y, x + 1);
		if (map->matrice_copy[y][x - 1] != '1')
			check_path(map, y, x - 1);
		if (map->matrice_copy[y - 1][x] != '1')
			check_path(map, y - 1, x);
		if (map->matrice_copy[y + 1][x] != '1')
			check_path(map, y + 1, x);
	}
}

void	check_and_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrice_copy[i])
	{
		free(map->matrice_copy[i]);
		i++;
	}
	free(map->matrice_copy);
	if (map->collectible_copy != 0 || map->exit != 1)
		ft_error("Error:There is no valid path!\n", map);
}

void	count_collectible(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	init_struct(map);
	while (map->matrice[y])
	{
		x = 0;
		while (map->matrice[y][x])
		{
			if (map->matrice[y][x] == 'P')
			{
				map->player++;
				map->position_y = y;
				map->position_x = x;
			}
			if (map->matrice[y][x] == 'C')
				map->collectible++;
			if (map->matrice[y][x] == 'E')
				map->exit++;
			x++;
		}
		y++;
	}
	map->collectible_copy = map->collectible;
}
