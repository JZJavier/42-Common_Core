/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_biubiu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:35:36 by yugao             #+#    #+#             */
/*   Updated: 2024/04/11 22:58:54 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// no importante , lo mas importante es la ultima funcion de este archivo
static t_pos	apoyo_biu_hit_pos_veri(t_pos start_pos, int ang)
{
	double	n_tan;

	ang = fix_ang (ang);
	n_tan = tan (fix_ang_to_rad (ang));
	if (cos(fix_ang_to_rad (ang)) > 0.001)
		return ((t_pos){(int)(start_pos.x) / UNI * UNI + UNI + 0.001,
			(((int)(start_pos.x) / UNI * UNI + UNI + 0.001) - start_pos.x)
				* n_tan + start_pos.y});
	else if (cos(fix_ang_to_rad (ang)) < -0.001)
		return ((t_pos){(int)(start_pos.x) / UNI * UNI - 0.001,
			(((int)(start_pos.x) / UNI * UNI - 0.0001) - start_pos.x)
				* n_tan + start_pos.y});
	else
		return ((t_pos){start_pos.x + cos (fix_ang_to_rad(ang))
			* 500, start_pos.y + sin(fix_ang_to_rad(ang)) * 500});
}

//no importante
static t_pos	bi_hit_pos_hori(t_pos start_pos, int ang)
{
	double	n_tan;
	double	s_tan;

	ang = fix_ang (ang);
	n_tan = tan (fix_ang_to_rad (ang));
	s_tan = 1.0 / n_tan;
	if (sin(fix_ang_to_rad (ang)) > 0.001)
		return ((t_pos){((((int)(start_pos.y) / UNI * UNI + UNI + 0.001))
			- start_pos.y) * s_tan + start_pos.x, (((int)(start_pos.y)
				/ UNI * UNI + UNI + 0.001))});
	else if (sin(fix_ang_to_rad (ang)) < -0.001)
		return ((t_pos){((((int)(start_pos.y) / UNI * UNI - 0.0001))
			- start_pos.y) * s_tan + start_pos.x, (((int)(start_pos.y)
				/ UNI * UNI - 0.0001))});
	else
		return ((t_pos){start_pos.x + cos (fix_ang_to_rad(ang))
			* 500, start_pos.y + sin(fix_ang_to_rad(ang)) * 500});
}

//这里有必要对循环的深度做限制, 一般是水平探查地图长度减一的深度 防止死循环
//no importante
static t_pos	biu_hit_pos_hori(void *info, int setoff_ang)
{
	int		ang;
	t_pos	p_mtx;
	t_pos	fin;
	int		i;

	ang = fix_ang(((t_info *)info)->ctr_ang.ang + setoff_ang);
	fin = bi_hit_pos_hori (((t_info *)info)->ctr_pos, ang);
	p_mtx = math_coordinate (fin);
	i = 0;
	if (sin(fix_ang_to_rad (ang)) > 0.001 || sin(fix_ang_to_rad (ang)) < -0.001)
	{
		while (i < ((t_info *)info)->mtx_size.x && m (info,
				(int)(p_mtx.x), (int)(p_mtx.y)) &&
				((t_info *)info)->mtx[(int)(p_mtx.x)][(int)(p_mtx.y)]->obj
					!= '1')
		{
			fin = bi_hit_pos_hori (fin, ang);
			p_mtx = math_coordinate (fin);
			i ++;
		}
		return (fin);
	}
	else
		return (bi_hit_pos_hori (((t_info *)info)->ctr_pos, ang));
}

//这里有必要对循环的深度做限制, 一般是纵向探查地图高度减一的深度 防止死循环
//no importante
static t_pos	biu_hit_pos_veri(void *info, int setoff_ang)
{
	int		ang;
	t_pos	p_mtx;
	t_pos	fin;
	int		i;

	ang = fix_ang(((t_info *)info)->ctr_ang.ang + setoff_ang);
	fin = apoyo_biu_hit_pos_veri (((t_info *)info)->ctr_pos, ang);
	p_mtx = math_coordinate (fin);
	i = 0;
	if (cos(fix_ang_to_rad (ang)) > 0.001 || cos(fix_ang_to_rad (ang)) < -0.001)
	{
		while (i < ((t_info *)info)->mtx_size.y
			&& m (info, (int)(p_mtx.x), (int)(p_mtx.y)) &&
				((t_info *)info)->mtx[(int)(p_mtx.x)][(int)(p_mtx.y)]->obj
					!= '1')
		{
			fin = apoyo_biu_hit_pos_veri (fin, ang);
			p_mtx = math_coordinate (fin);
			i ++;
		}
		return (fin);
	}
	else
		return (apoyo_biu_hit_pos_veri (((t_info *)info)->ctr_pos, ang));
}

//从人物的角度初发, 以与人物角度差为setoff_ang的角度发出射线, 
//返回一个与墙面的交点, 并存储有交点的位置信息, 例如交点是在墙的左边右边上边还是下边
//From the character's point of view of the first shot, with the character's 
//angle difference for the setoff_ang angle of the ray, to return to a point 
//of intersection with the wall, and store the 
//location of the point of intersection of 
//information, such as intersection is in the wall of the 
//left side of the right side of the upper edge or lower edge

t_posx	biu_hit_pos(void *info, int setoff_ang)
{
	t_pos	hori;
	t_pos	veri;
	t_posx	fin;
	double	dis_hori;
	double	dis_veri;

	hori = biu_hit_pos_hori (info, setoff_ang);
	veri = biu_hit_pos_veri (info, setoff_ang);
	dis_hori = math_dist2p(((t_info *)info)->ctr_pos, hori);
	dis_veri = math_dist2p(((t_info *)info)->ctr_pos, veri);
	fin = apoyo_biu1 ((t_info *)info, hori, veri, setoff_ang);
	if (fin.side != -1)
		return (fin);
	if (dis_hori < dis_veri)
		return (apoyo_biu2 ((t_info *)info, hori, veri, TRUE));
	else
		return (apoyo_biu2 ((t_info *)info, hori, veri, FALSE));
}

//void	biu_2d(void *info);

// int	main(void)
// {
// 	printf ("%f", tan (fix_rad( PI + PI / 3)));
// 	return 0;
// }