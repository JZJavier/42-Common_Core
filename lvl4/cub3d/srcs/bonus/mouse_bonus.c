/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:08:51 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/11 22:54:04 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	mouse_move_hook(int x, int y, t_info *info)
{
	(void)y;
	mlx_mouse_move(info->win, info->map_info.x / 2, info->map_info.y / 2);
	if (info->map_info.x / 2 > x)
		info->ctr_ang = math_projection_vec (info->ctr_ang, -5, 5);
	if (info->map_info.x / 2 < x)
		info->ctr_ang = math_projection_vec (info->ctr_ang, +5, 5);
	keep_draw (*info);
	return (0);
}

int	mouse_shoot(int button, int x, int y, t_info *info)
{
	if (button == 1)
		dispara(info);
	(void)x;
	(void)y;
	return (0);
}
