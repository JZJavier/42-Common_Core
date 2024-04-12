/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_biu_apoyo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:07:41 by yugao             #+#    #+#             */
/*   Updated: 2024/04/10 19:21:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_posx	apoyo_biu1(t_info *info, t_pos hori, t_pos veri, int setoff_ang)
{
	t_pos	ctr;

	ctr = info->ctr_pos;
	if (fix_ang (setoff_ang + info->ctr_ang.ang) == 0
		|| fix_ang (setoff_ang + info->ctr_ang.ang) == 180)
	{
		if (veri.x < ctr.x)
			return (trans_pos_to_posx (veri, RIGHTSIDE));
		else
			return (trans_pos_to_posx (veri, LEFTSIDE));
	}
	if (fix_ang (setoff_ang + info->ctr_ang.ang) == 90
		|| fix_ang (setoff_ang + info->ctr_ang.ang) == 270)
	{
		if (hori.y < ctr.y)
			return (trans_pos_to_posx (hori, DOWNSIDE));
		else
			return (trans_pos_to_posx (hori, UPSIDE));
	}
	return (trans_pos_to_posx ((t_pos){-1, -1}, -1));
}

t_posx	apoyo_biu2(t_info *info, t_pos hori, t_pos veri, t_bool isveri_big)
{
	t_pos	ctr;

	ctr = info->ctr_pos;
	if (isveri_big)
	{
		if (hori.y < ctr.y)
			return (trans_pos_to_posx (hori, DOWNSIDE));
		else
			return (trans_pos_to_posx (hori, UPSIDE));
	}
	else
	{
		if (veri.x < ctr.x)
			return (trans_pos_to_posx (veri, RIGHTSIDE));
		else
			return (trans_pos_to_posx (veri, LEFTSIDE));
	}
}
