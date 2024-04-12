/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:32:20 by yugao             #+#    #+#             */
/*   Updated: 2024/04/10 18:10:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
//求两个向量的夹角
//Find the angle between two vectors(no used)
double	ang_2vec_2d(t_vec v1, t_vec v2)
{
	double	doc_multi;
	double	len_multi;

	doc_multi = v1.vx * v2.vx + v1.vy * v2.vy;
	len_multi = sqrt (v1.vx * v1.vx + v1.vy * v1.vy)
		* sqrt (v2.vx * v2.vx + v2.vy * v2.vy);
	return (acos(doc_multi / len_multi));
}

//将向量坐标进行旋转变换
// Rotate the vector coordinates. (no used)
void	vec_rotate(t_vec *v_ori, double ang)
{
	double	vx_tem;

	vx_tem = v_ori->vx;
	v_ori->vx = cos (ang) * v_ori->vx - sin (ang) * v_ori->vy;
	v_ori->vy = sin (ang) * vx_tem + cos (ang) * v_ori->vy;
}

//将向量坐标进行缩放
// Scale the vector coordinates (no used)
void	vec_scale(t_vec *v_ori, double scale_x, double scale_y)
{
	v_ori->vx = v_ori->vx * scale_x;
	v_ori->vy = v_ori->vy * scale_y;
}

//将原坐标点像向量方向进行位移, 向量不是单位向量
//Displace the original coordinate point in
// the direction of the vector, which is not a unit vector.
t_pos	vec_trans(t_pos p_ori, t_vec v_direction, t_bool is_forward)
{
	if (is_forward)
		return ((t_pos){p_ori.x + v_direction.vx, p_ori.y + v_direction.vy});
	else
		return ((t_pos){p_ori.x - v_direction.vx, p_ori.y - v_direction.vy});
}
