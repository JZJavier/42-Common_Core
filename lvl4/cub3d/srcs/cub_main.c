/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 05:03:30 by yugao             #+#    #+#             */
/*   Updated: 2024/04/09 02:25:15 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*void leaks()
{
	system("leaks -q cub3d");
}*/

static int	close_win(void)
{
	exit(2);
	return (2);
}

t_pos	init_ctr_pos(t_mtx matrix)
{
	int	x;
	int	y;

	y = 0;
	while (matrix[0][y])
	{
		x = 0;
		while (matrix[x] && matrix[x][y])
		{
			if (matrix[x][y]->obj == 'N' || matrix[x][y]->obj == 'S'
				|| matrix[x][y]->obj == 'W' || matrix[x][y]->obj == 'E')
			{
				matrix[x][y]->obj = '0';
				return ((t_pos){x * UNI + UNI / 2, y * UNI + UNI / 2});
			}
			x ++;
		}
		y ++;
	}
	return ((t_pos){0, 0});
}

static t_bool	ap_map_check(t_mtx mtx, int x, int y)
{
	if (mtx[x][y]->obj != '1' && mtx[x][y]->obj != '0')
		return (FALSE);
	return (TRUE);
}

t_bool	map_check(t_mtx mtx, t_size size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (mtx[x][y] && mtx[x][y]->obj == '0')
			{
				if (!(y - 1 >= 0) || !ap_map_check (mtx, x, y - 1))
					return (FALSE);
				if (!(y + 1 < size.y) || !ap_map_check (mtx, x, y + 1))
					return (FALSE);
				if (!(x - 1 >= 0) || !ap_map_check (mtx, x - 1, y))
					return (FALSE);
				if (!(x + 1 < size.x) || !ap_map_check (mtx, x + 1, y))
					return (FALSE);
			}
			x ++;
		}
		y ++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_parse	parse;

	if (argc != 2)
		return (printf("Error: Wrong number of arguments, only 1 expected\n"));
	get_dimension(&parse, argv[1]);
	if (map_parsing(&parse, argv[1]) == -1)
		return (-1);
	init_info(&info, parse, init_vec (parse), (t_map){TEM_MAP_LEN, 510});
	if (map_check (info.mtx, info.mtx_size) == FALSE)
	{
		printf ("Cub3d: is not close by walls(1)\n");
		destory_all (&info, &parse);
		exit (0);
	}
	init_draw (info);
	mlx_hook (info.win, 2, 1L << 0, key_press, &info);
	mlx_hook (info.win, 3, 1L << 1, key_release, &info);
	mlx_loop_hook (info.mlx, (void *)key_move, &info);
	mlx_hook(info.win, 17, 0, close_win, NULL);
	mlx_loop(info.mlx);
	return (0);
}
