/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_graph_ray_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:29:57 by yugao             #+#    #+#             */
/*   Updated: 2024/04/11 22:39:56 by javgao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
//画一条射线, 需要提供结束点的坐标, 因为起始点的坐标就是人物坐标ctr_pos
// draw a ray, need to provide the coordinates of the end point,
// because the coordinates of the start 
//point is the character coordinates ctr_pos
void	graph_draw_ray(void *info, t_pos endpoint)
{
	graph_thick_line (info, ((t_info *)info)->ctr_pos, endpoint, 1);
}

//根据撞击点的方向判断应该应用什么类型的材质
//Determine what type of material should be 
//applied based on the direction of the point of impact.
static t_img_info	pick_tex(void *info, t_bool side)
{
	t_info	*tem;

	tem = (t_info *)info;
	if (side == UPSIDE)
		return (tem->tex_up);
	else if (side == DOWNSIDE)
		return (tem->tex_down);
	else if (side == LEFTSIDE)
		return (tem->tex_left);
	else
		return (tem->tex_right);
}

static t_size	ap_g_tex(int y, int line_h, t_img_info tex, t_posx hit)
{
	int	y_tex;
	int	x_tex;

	y_tex = (int)(((double)y / line_h) * tex.tex_y);
	if (hit.side == LEFTSIDE || hit.side == RIGHTSIDE)
		x_tex = (int)((int)(hit.y - (int)(hit.y / UNI)*UNI) % tex.tex_y);
	else
		x_tex = (int)((int)(hit.x - (int)(hit.x / UNI)*UNI) % tex.tex_x);
	return ((t_size){x_tex, y_tex});
}

static void	graph_texture(t_info *info, t_posx hit,
	t_img_info tex, t_vec x_y_ang)
{
	int		line_h;
	int		line_off;
	int		y;
	t_size	x_y;

	line_h = (int)((double)UNI / ((math_dist2p(info->ctr_pos,
						trans_posx_to_pos(hit))
					* cos(fix_ang_to_rad(fix_ang(x_y_ang.ang)))))
			* SCREENWITH / (2.0 * tan(fix_ang_to_rad(fix_ang(FOV / 2)))));
	line_off = (SCREENWITH / 2) - (line_h / 2);
	y = 0;
	while (y < line_h)
	{
		x_y = ap_g_tex (y, line_h, tex, hit);
		img_put_pixel(info, x_y_ang.vx + TEM_SETOFF, y + line_off,
			*(uint32_t *)(tex.addr + (x_y.y * tex.len_line)
				+ x_y.x * (tex.bits_per_pixel / 8)));
		y ++;
	}
}

//这里FOV是视角的大小, 通过这个函数我们可以生成3d场景
// Here FOV is the size of the viewpoint, 
//with this function we can generate a 3d scene.
void	graph_ray_to_wall(t_info *info)
{
	int			y;
	int			x;
	t_img_info	tex;
	t_posx		hit;
	double		setoff_ang;

	x = 0;
	y = 0;
	while (x < SCREENWITH)
	{
		setoff_ang = (x - SCREENWITH / 2.0) * (FOV / (double)SCREENWITH);
		hit = biu_hit_pos(info, setoff_ang);
		if (info->mtx[(int)(hit.x / UNI)][(int)(hit.y / UNI)]->obj == 'D')
			tex = info->door;
		else if (info->mtx[(int)(hit.x / UNI)][(int)(hit.y / UNI)]->obj == 'M')
			tex = info->emp;
		else
			tex = pick_tex (info, hit.side);
		graph_texture (info, hit, tex, (t_vec){x, y, setoff_ang});
		x ++;
	}
}
