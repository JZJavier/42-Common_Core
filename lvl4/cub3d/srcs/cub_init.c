/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:53:08 by yugao             #+#    #+#             */
/*   Updated: 2024/04/09 02:21:21 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_img(t_info *info, t_parse parse)
{
	if (init_texture(info, parse) == -1)
	{
		perror("Error: Not a valid .xpm file");
		exit (2);
	}
	info->tex_down.addr = mlx_get_data_addr (info->tex_down.img,
			&(info->tex_down.bits_per_pixel),
			&(info->tex_down.len_line), &(info->tex_down.endian));
	info->tex_up.addr = mlx_get_data_addr (info->tex_up.img,
			&(info->tex_up.bits_per_pixel),
			&(info->tex_up.len_line), &(info->tex_up.endian));
	info->tex_left.addr = mlx_get_data_addr (info->tex_left.img,
			&(info->tex_left.bits_per_pixel),
			&(info->tex_left.len_line), &(info->tex_left.endian));
	info->tex_right.addr = mlx_get_data_addr (info->tex_right.img,
			&(info->tex_right.bits_per_pixel),
			&(info->tex_right.len_line), &(info->tex_right.endian));
}

void	init_info(t_info *info, t_parse prase,
	t_vec ori_ang, t_map map)
{
	info->mlx = mlx_init ();
	info->win = mlx_new_window (info->mlx, map.x, map.y, "cub3D");
	info->mtx = matrix_init (ori_ang);
	matrix_push (&info->mtx, prase.map);
	info->mtx_size = (t_size){(int)ori_ang.vx, (int)ori_ang.vy};
	info->map_info = map;
	info->ctr_ang = ori_ang;
	info->ctr_ang.vx = cos (fix_ang_to_rad (ori_ang.ang)) * 15;
	info->ctr_ang.vy = sin (fix_ang_to_rad (ori_ang.ang)) * 15;
	info->ctr_pos = init_ctr_pos (info->mtx);
	info->key.up = 0;
	info->key.down = 0;
	info->key.left = 0;
	info->key.right = 0;
	info->key.to_left = 0;
	info->key.to_right = 0;
	info->key.show = 0;
	info->img_info.img = NULL;
	init_img (info, prase);
	info->color = 0xFFFFFF;
	info->color_sky = trans_rgb_to_dig (hash_grep (prase.hs, "C"));
	info->color_floor = trans_rgb_to_dig (hash_grep (prase.hs, "F"));
}

void	init_is_valid(t_parse *parse)
{
	parse->hs = hash_init();
	parse->is_valid[0] = "NO";
	parse->is_valid[1] = "SO";
	parse->is_valid[2] = "WE";
	parse->is_valid[3] = "EA";
	parse->is_valid[4] = "F";
	parse->is_valid[5] = "C";
	parse->is_valid[6] = NULL;
	parse->num = 0;
	parse->fd = -1;
	parse->len_to_space = 0;
	parse->line = NULL;
	parse->join = NULL;
	parse->temp = NULL;
	parse->out_nl = NULL;
	parse->with_spaces = NULL;
}

int	is_valid(char *line, t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->is_valid[i] != NULL)
	{
		if ((ft_strcmp (line, parse->is_valid[i]) == 0))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	init_elements(t_parse *parse)
{
	char	*line;
	char	*temp;
	char	*value;
	char	*valfin;

	while (parse->num != ELEMENTS_MAP)
	{
		line = get_next_line(parse->fd);
		if (line == NULL)
			return (close(parse->fd), -1);
		parse->len_to_space = ft_strchrlen(line, ' ');
		temp = ft_substr(line, 0, parse->len_to_space);
		if (is_valid(temp, parse) == TRUE)
			parse->num++;
		value = ft_substr(line, parse->len_to_space, ft_strlen(line));
		valfin = ft_strtrim (value, " \n");
		hash_push(parse->hs, temp, valfin);
		free_three(valfin, value, temp);
		if (is_valid(temp, parse) == FALSE && is_space(line) != 0)
			return (close(parse->fd), free(line), hash_destory(parse->hs), -1);
		free(line);
	}
	if (map_read(parse, parse->fd) == -1)
		return (close(parse->fd), -1);
	return (TRUE);
}
