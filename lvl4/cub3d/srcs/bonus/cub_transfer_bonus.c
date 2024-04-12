/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_transfer_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:16:05 by yugao             #+#    #+#             */
/*   Updated: 2024/04/10 18:10:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
//将t_posx类型的变量转换为t_pos类型
// Convert a variable of type t_posx to t_pos
t_pos	trans_posx_to_pos(t_posx posx)
{
	return ((t_pos){posx.x, posx.y});
}

//将两个数字转换为t_pos类型变量
// Convert two numbers into a variable of type t_pos
t_pos	trans_2num_to_pos(double n1, double n2)
{
	return ((t_pos){n1, n2});
}

//将t_pos类型的变量转换为t_posx类型
// Convert a variable of type t_pos to t_posx
t_posx	trans_pos_to_posx(t_pos pos, t_bool side)
{
	return ((t_posx){pos.x, pos.y, side});
}

unsigned int	trans_rgb_to_dig(char *rgb_str)
{
	char			**rgb_components;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	fin;

	rgb_components = ft_split(rgb_str, ',');
	if (!rgb_components)
	{
		printf("Error: Unable to split the RGB string.\n");
		return (0);
	}
	r = (unsigned int)ft_atoi(rgb_components[0]);
	g = (unsigned int)ft_atoi(rgb_components[1]);
	b = (unsigned int)ft_atoi(rgb_components[2]);
	fin = (r << 16) | (g << 8) | b;
	arry_destroy (rgb_components);
	return (fin);
}
