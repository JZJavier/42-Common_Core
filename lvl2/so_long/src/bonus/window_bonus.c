/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:05:18 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 00:53:31 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_xpm(t_map *map)
{
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr, PLAYER_DOWN,
			&map->img_width, &map->img_height);
	if (map->img_player == NULL)
		ft_error("Error: Player.xpm couldn't be opened!", map);
	map->img_collectible = mlx_xpm_file_to_image(map->mlx_ptr, COLLECTIBLE,
			&map->img_width, &map->img_height);
	if (map->img_collectible == NULL)
		ft_error("Error: Collectible.xpm couldn't be opened!", map);
	map->img_floor = mlx_xpm_file_to_image(map->mlx_ptr, FLOOR,
			&map->img_width, &map->img_height);
	if (map->img_floor == NULL)
		ft_error("Error: Floor.xpm couldn't be opened!", map);
	map->img_exit = mlx_xpm_file_to_image(map->mlx_ptr, EXIT,
			&map->img_width, &map->img_height);
	if (map->img_exit == NULL)
		ft_error("Error: Exit.xpm couldn't be opened!", map);
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, WALL,
			&map->img_width, &map->img_height);
	if (map->img_wall == NULL)
		ft_error("Erro: Wall.xpm couldn't be opened!", map);
	map->img_enemy = mlx_xpm_file_to_image(map->mlx_ptr, ENEMY,
			&map->img_width, &map->img_height);
	if (map->img_enemy == NULL)
		ft_error("Error: Enemy.xpm couldn't be opened!", map);
}

int	open_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (-1);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->map_width,
			map->map_height, "SO_LONG BONUS");
	if (map->win_ptr == NULL)
		return (free(map->mlx_ptr), -1);
	init_xpm(map);
	return (0);
}
