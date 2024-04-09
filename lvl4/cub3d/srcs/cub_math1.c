/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_math1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 04:58:10 by yugao             #+#    #+#             */
/*   Updated: 2024/04/04 01:43:01 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//计算两点之间的距离
//Calculate the distance between two points
double	math_dist2p(t_pos p1, t_pos p2)
{
	double	dy;
	double	dx;

	dy = fabs (p2.y - p1.y);
	dx = fabs (p2.x - p1.x);
	return (sqrt(dx * dx + dy * dy));
}

//计算两点之间直线方程的的斜率k
//Calculate the slope of the equation of the line between two points k
double	math_k2p(t_pos p1, t_pos p2)
{
	return ((p2.y - p1.y) / (p2.x - p1.x));
}

//计算两点之间直线方程的常量数值
// Calculate the constant value of the equation of a line between two points
double	math_b2p(t_pos p, double k)
{
	return (p.y - k * p.x);
}

//当给定两点后, 设定偏移量offset 根据需要的坐标求出便宜后直线对应的坐标
//When two points are given, set the offset and find out 
//the coordinates of the cheap line according to the required coordinates.
t_pos	math_line_offset(t_pos p_esp, t_pos p1, t_pos p2, double b_offset)
{
	double	k;
	double	b;

	k = math_k2p (p1, p2);
	b = math_b2p (p1, k) + b_offset;
	return ((t_pos){p_esp.x, k * p_esp.x + b});
}
