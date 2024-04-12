/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_graph_base_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:51:23 by yugao             #+#    #+#             */
/*   Updated: 2024/04/10 18:10:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
//这里传入的是一个t_info类型的 但是必须要求t_info里的img_info已经通过new_img函数进行初始化才可以
//There is a t_info type passed in, but only if 
//the img_info in the t_info has been initialized with the new_img function.
static void	graph_line(void *info, t_pos p1, t_pos p2)
{
	double	dx;
	double	dy;
	double	e;
	int		i;

	i = -1;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (fabs(dx) > fabs(dy))
		e = fabs(dx);
	else
		e = fabs(dy);
	dx = dx / e;
	dy = dy / e;
	while (++ i < e)
	{
		img_put_pixel(info, (int)(p1.x + 0.5),
			(int)(p1.y + 0.5), ((t_info *)info)->color);
		p1.x += dx;
		p1.y += dy;
	}
}

//画一个有厚度的直线, 这里处理的是当直线的斜率绝对值大于1的情况
// draws a straight line with a thickness, here we are dealing 
//with the case when the absolute value of 
//the slope of the line is greater than 1.
static void	graph_thick_line_plumb(void *info, t_pos p1, t_pos p2, double thick)
{
	double	i;

	if (thick == 0)
		thick = 1;
	i = -(thick / 2);
	while (i < thick / 2)
	{
		graph_line (info, (t_pos){p1.x + i, p1.y}, (t_pos){p2.x + i, p2.y});
		i ++;
	}
}

//画一个有厚度的直线, 这里处理的是当直线的斜率小于1的情况
// draws a straight line with a thickness, here it deals
// with the case when the slope of the line is less than 1.
void	graph_thick_line(void *info, t_pos p1, t_pos p2, double thick)
{
	double	i;

	if (p1.x == p2.x || fabs (math_k2p(p1, p2)) > 1)
		graph_thick_line_plumb (info, p1, p2, thick);
	else
	{
		i = -thick / 2;
		while (i < thick / 2)
		{
			graph_line (info, math_line_offset (p1, p1, p2, i),
				math_line_offset (p2, p1, p2, i));
			i ++;
		}
	}
}

//画一个正方形, 需要提供中心点的坐标和边长
//Draw a square, you need to provide the coordinates 
//of the center point and the length of the side.
void	graph_square(void *info, t_pos p_center, int len_side)
{
	if (len_side % 2 == 0)
		graph_thick_line (info, (t_pos){p_center.x, p_center.y
			- (int)(len_side / 2 + 0.5)}, (t_pos){p_center.x,
			p_center.y + (int)(len_side / 2 + 0.5)}, len_side);
	else
		graph_thick_line (info, (t_pos){p_center.x, p_center.y
			- len_side / 2}, (t_pos){p_center.x, p_center.y
			+ len_side - len_side / 2}, len_side);
}

//画一个长方形, 这里需要提供左下角和右上角的坐标
//Draw a rectangle, here you need to provide the 
//coordinates of the lower left and upper right corners.
void	graph_rectangle(void *info, t_pos p_low_left, t_pos p_up_right)
{
	int	i;

	i = p_low_left.x;
	while (i <= p_up_right.x)
	{
		graph_thick_line (info, (t_pos){p_low_left.x
			+ i, p_low_left.y}, (t_pos){p_low_left.x + i, p_up_right.y}, 1);
		i ++;
	}
}
