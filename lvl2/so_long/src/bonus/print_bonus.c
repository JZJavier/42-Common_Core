/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:00:20 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 01:12:21 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_floor(t_map *map)
{
	int	y;
	int	x;
	int	x_pos;
	int	y_pos;

	y = 0;
	while (map->matrice[y])
	{
		x = 0;
		while (map->matrice[y][x])
		{
			x_pos = x * 56;
			y_pos = y * 56;
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
				map->img_floor, x_pos, y_pos);
			x++;
		}
		y++;
	}
}

void	draw_img(int y, int x, t_map *map)
{
	char	c;

	c = map->matrice[y][x];
	if (c == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img_wall, x * 56, y * 56);
	if (c == 'P')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img_player, x * 56, y * 56);
	if (c == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img_collectible, x * 56, y * 56);
	if (c == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img_exit, x * 56, y * 56);
	if (c == 'K')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->img_enemy, x * 56, y * 56);
}

void	print_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	print_floor(map);
	while (map->matrice[y])
	{
		x = 0;
		while (map->matrice[y][x])
		{
			draw_img(y, x, map);
			x++;
		}
		y++;
	}
}

void	choose_player(t_map *map, int y, int x)
{
	if (y == 1)
		map->dir = "./sprites/Player.xpm";
	if (y == -1)
		map->dir = "./sprites/Player_Up.xpm";
	if (x == 1)
		map->dir = "./sprites/Player_Right.xpm";
	if (x == -1)
		map->dir = "./sprites/Player_Left.xpm";
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr, map->dir,
			&map->img_width, &map->img_height);
	if (map->img_player == NULL)
		ft_error("\nImage couldn't be opened!", map);
}
