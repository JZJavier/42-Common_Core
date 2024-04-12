/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:31:39 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/10 21:33:18 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	check_walls(t_parse *parse, char *map)
{
	int		i;
	char	*new_map;
	char	*space;

	i = 0;
	space = ft_strdup(" ");
	new_map = ft_strjoin(space, map);
	while (new_map[i] && new_map[i + 1])
	{
		if (new_map[i] == '0' || new_map[i] == 'N' || new_map[i] == 'S'
			|| new_map[i] == 'W' || new_map[i] == 'E' || new_map[i] == 'D')
		{
			if (new_map[i - 1] == ' ' || new_map[i + 1] == ' ')
				return (free_three_hsh(parse, space, new_map, parse->map), -1);
		}
		i++;
	}
	free(new_map);
	free (space);
	return (0);
}

int	get_dimension(t_parse *parse, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	parse->height = 0;
	parse->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (check_invalid_characters(line, 0) == 0 && is_space(line) == -1)
		{
			get_width(parse, line);
			parse->height++;
		}
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}

void	get_width(t_parse *parse, char *line)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len > parse->width)
		parse->width = line_len;
}
