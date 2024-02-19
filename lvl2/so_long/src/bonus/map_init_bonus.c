/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:28:51 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:06 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	*map_one_str(char *filename)
{
	int		fd;
	int		bytes;
	char	*buf;

	buf = (char *) malloc (FILESIZE + 1);
	if (buf == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free (buf);
		perror("Error: open failed on data_one_str function");
		return (NULL);
	}
	bytes = read(fd, buf, FILESIZE);
	if (bytes == -1)
	{
		free (buf);
		close (fd);
		perror("Error: reading the file on data_one_str function");
		return (NULL);
	}
	buf[bytes] = '\0';
	close (fd);
	return (buf);
}

void	get_dimensions(t_map *map)
{
	char	**matrice;
	int		x;
	int		y;

	matrice = map->matrice;
	x = 0;
	y = 0;
	while (matrice[y++])
		map->map_height++;
	while (matrice[0][x++])
		map->map_width++;
	map->map_height = map->map_height * 56;
	map->map_width = map->map_width * 56;
}

void	map_matrice(t_map *map, char *filename)
{
	char	*mapa;

	mapa = map_one_str(filename);
	if (mapa == NULL)
	{
		perror ("Error: Malloc failed on map_matrice function\n");
		return ;
	}
	map->matrice = ft_split(mapa, '\n');
	if (map->matrice == NULL)
	{
		perror ("Error: ft_split failed on map_matrice\n");
		return ;
	}
	map->matrice_copy = ft_split(mapa, '\n');
	if (map->matrice_copy == NULL)
	{
		perror ("Error: ft_split failed on data_matrice\n");
		return ;
	}
	map->status = 1;
	get_dimensions(map);
	free(mapa);
}
