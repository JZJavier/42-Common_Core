/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:56:47 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/20 17:47:11 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_moves_screen(t_map *map)
{
	char	*str;

	str = ft_itoa(map->moves);
	mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 27, 0x000000, "Moves: ");
	mlx_string_put(map->mlx_ptr, map->win_ptr, 75, 27, 0x000000, str);
	free(str);
}

void	move_player(t_map *map, int y, int x)
{
	int	new_y;
	int	new_x;

	new_y = map->position_y + y;
	new_x = map->position_x + x;
	if (map->matrice[new_y][new_x] == 'K')
		exit(2);
	else if (map->matrice[new_y][new_x] == 'C')
		map->collectible--;
	else if (map->matrice[new_y][new_x] == 'E' && map->collectible == 0)
		exit (0);
	if (map->matrice[new_y][new_x] != '1' && map->matrice[new_y][new_x] != 'E')
	{
		map->matrice[map->position_y][map->position_x] = '0';
		map->matrice[new_y][new_x] = 'P';
		map->position_y = new_y;
		map->position_x = new_x;
		map->moves++;
		choose_player(map, y, x);
		ft_printf("\n%d", map->moves);
		print_map(map);
		print_moves_screen(map);
	}
}

int	handle_movement(int key, t_map *map)
{
	if (key == UP)
		move_player(map, -1, 0);
	if (key == DOWN)
		move_player(map, 1, 0);
	if (key == LEFT)
		move_player(map, 0, -1);
	if (key == RIGHT)
		move_player(map, 0, 1);
	return (0);
}

int	detect_key(int key, t_map *map)
{
	if (key == ESC)
		exit(0);
	handle_movement(key, map);
	return (0);
}
