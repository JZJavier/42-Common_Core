/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:15:31 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:04 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_struct(t_map *map)
{
	map->player = 0;
	map->collectible = 0;
	map->exit = 0;
	map->moves = 0;
	map->map_height = 0;
	map->map_width = 0;
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		if (map_validate(argv[1]) == 0)
		{
			init_struct(&map);
			map_matrice(&map, argv[1]);
			count_collectible(&map);
			get_dimensions(&map);
			check_path(&map, map.position_y, map.position_x);
			check_and_free(&map);
			open_window(&map);
			print_map(&map);
			mlx_key_hook(map.win_ptr, detect_key, &map);
			mlx_loop(map.mlx_ptr);
		}
	}
	else
		perror("Error: ./so_long data: a valid path to the data is missing:");
	system ("leaks -q so_long");
	return (0);
}
