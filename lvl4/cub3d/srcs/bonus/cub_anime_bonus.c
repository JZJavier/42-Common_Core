/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_anime_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:03:58 by javgao            #+#    #+#             */
/*   Updated: 2024/04/11 23:02:12 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	init_tex_anime(t_info *info)
{
	info->anime.ani1.img = mlx_xpm_file_to_image (info->mlx,
			"./texture/gun/gun_1.xpm",
			&info->anime.ani1.tex_x, &info->anime.ani1.tex_y);
	if (info->anime.ani1.img == NULL)
		return (-1);
	info->anime.ani2.img = mlx_xpm_file_to_image (info->mlx,
			"./texture/gun/gun_2.xpm",
			&info->anime.ani2.tex_x, &info->anime.ani2.tex_y);
	if (info->anime.ani2.img == NULL)
		return (-1);
	info->anime.ani3.img = mlx_xpm_file_to_image (info->mlx,
			"./texture/gun/gun_3.xpm",
			&info->anime.ani3.tex_x, &info->anime.ani3.tex_y);
	if (info->anime.ani3.img == NULL)
		return (-1);
	info->anime.ani4.img = mlx_xpm_file_to_image (info->mlx,
			"./texture/gun/gun_4.xpm",
			&info->anime.ani4.tex_x, &info->anime.ani4.tex_y);
	if (info->anime.ani4.img == NULL)
		return (-1);
	info->anime.ani5.img = mlx_xpm_file_to_image (info->mlx,
			"./texture/gun/gun_5.xpm",
			&info->anime.ani5.tex_x, &info->anime.ani5.tex_y);
	return (0);
}

void	init_img_tex(t_info *info)
{
	if (init_tex_anime(info) == -1)
	{
		perror("Error: Not a valid .xpm file");
		exit (2);
	}
	info->anime.ani1.addr = mlx_get_data_addr (info->anime.ani1.img,
			&(info->anime.ani1.bits_per_pixel),
			&(info->anime.ani1.len_line), &(info->anime.ani1.endian));
	info->anime.ani2.addr = mlx_get_data_addr (info->anime.ani2.img,
			&(info->anime.ani2.bits_per_pixel),
			&(info->anime.ani2.len_line), &(info->anime.ani2.endian));
	info->anime.ani3.addr = mlx_get_data_addr (info->anime.ani3.img,
			&(info->anime.ani3.bits_per_pixel),
			&(info->anime.ani3.len_line), &(info->anime.ani3.endian));
	info->anime.ani4.addr = mlx_get_data_addr (info->anime.ani4.img,
			&(info->anime.ani4.bits_per_pixel),
			&(info->anime.ani4.len_line), &(info->anime.ani4.endian));
	info->anime.ani5.addr = mlx_get_data_addr (info->anime.ani5.img,
			&(info->anime.ani5.bits_per_pixel),
			&(info->anime.ani5.len_line), &(info->anime.ani5.endian));
	info->anime.ani5.addr = mlx_get_data_addr (info->anime.ani5.img,
			&(info->anime.ani5.bits_per_pixel),
			&(info->anime.ani5.len_line), &(info->anime.ani5.endian));
}

void	dispara(t_info *info)
{
	t_posx	hit;

	info->key.up = 0;
	info->key.down = 0;
	info->key.left = 0;
	info->key.right = 0;
	info->key.to_left = 0;
	info->key.to_right = 0;
	info->key.show = 0;
	mlx_put_image_to_window (info->mlx, info->win, info->anime.ani1.img,
		300, 390);
	mlx_put_image_to_window (info->mlx, info->win, info->anime.ani2.img,
		300, 390);
	mlx_put_image_to_window (info->mlx, info->win, info->anime.ani3.img,
		300, 390);
	mlx_put_image_to_window (info->mlx, info->win, info->anime.ani4.img,
		300, 390);
	mlx_put_image_to_window (info->mlx, info->win, info->anime.ani5.img,
		300, 390);
	hit = biu_hit_pos ((void *)info, 0);
	if (info->mtx[(int)(hit.x / UNI)][(int)(hit.y / UNI)]->obj == '1')
		info->mtx[(int)(hit.x / UNI)][(int)(hit.y / UNI)]->obj = 'M';
}
