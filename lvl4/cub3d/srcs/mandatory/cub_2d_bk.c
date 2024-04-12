/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_2d_bk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:11:55 by yugao             #+#    #+#             */
/*   Updated: 2024/04/10 19:21:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// Draw a small 2d background, based on the incoming 
//matrix data  (t_info *)info->mtx.
//画一个2d的小背景, 根据传入的矩阵数据进行绘画
void	bk_map(void *info)
{
	int	x;
	int	y;

	y = -1;
	while (((t_info *)info)->mtx[0][++y])
	{
		x = -1;
		while (((t_info *)info)->mtx[++x])
		{
			if (((t_info *)info)->mtx[x][y]->obj == '1')
				img_set_color (info, 0x2E8B57);
			else if (((t_info *)info)->mtx[x][y]->obj == '0')
				img_set_color (info, 0xF0FFF0);
			else
				img_set_color (info, 0x000000);
			graph_square (info, (t_pos){(x * 10 + 10 / 2),
				(y * 10 + 10 / 2)}, 9);
		}
	}
}

//void	bk_razer(void *info, )