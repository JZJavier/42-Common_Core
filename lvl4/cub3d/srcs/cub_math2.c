/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:20:44 by yugao             #+#    #+#             */
/*   Updated: 2024/04/06 01:22:20 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//计算非单位向量在x和y轴上的分向量
// Calculate the component vectors of non-unit vectors on the x and y axes
t_vec	math_projection_vec(t_vec v_ori, double change_ang, int vec_len)
{
	int	new_ang;

	if (vec_len <= 0)
		vec_len = 1;
	new_ang = fix_ang (v_ori.ang + change_ang);
	return ((t_vec){cos (fix_ang_to_rad(new_ang))
		* vec_len, sin (fix_ang_to_rad(new_ang)) * vec_len, new_ang});
}

//根据我们自己设定的每个单位的大小, 由像素坐标计算单位坐标
// Calculate the unit coordinates from the pixel 
//coordinates according to the size of each unit we set ourselves.
t_pos	math_coordinate(t_pos pos)
{
	return ((t_pos){pos.x / UNI, pos.y / UNI});
}
