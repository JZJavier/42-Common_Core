/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:57:42 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/10 19:21:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_cub_extension_and_file(char *filename)
{
	char	*extension;
	int		fd;

	extension = ft_strrchr(filename, '.');
	if (!(ft_strcmp(extension, ".cub") == 0))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-2);
	close (fd);
	return (0);
}

int	check_duplicated_starting_position(t_parse *parse)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (parse->map[i])
	{
		if (parse->map[i] == 'N' || parse->map[i] == 'S'
			|| parse->map[i] == 'E' || parse->map[i] == 'W')
		{
			count++;
			parse->starting_position = parse->map[i];
		}
		i++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	check_invalid_characters(char *line, int print)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' '
			|| (line[i] >= 9 && line[i] <= 13))
			i++;
		else
		{
			if (print == 1)
				perror("Error: data file contains invalid characters:");
			return (-1);
		}
	}
	return (0);
}

int	map_read(t_parse *parse, int fd)
{
	parse->join = ft_strdup("");
	parse->line = get_next_line(fd);
	while (parse->line && *parse->line == '\n')
	{
		free (parse->line);
		parse->line = get_next_line(fd);
	}
	while (parse->line != NULL)
	{
		if (check_invalid_characters(parse->line, 1) == -1)
			return (free_two_and_hash(parse, parse->line, parse->join), -1);
		parse->out_nl = ft_strtrim(parse->line, "\n");
		parse->with_spaces = add_space(parse, parse->out_nl);
		free(parse->out_nl);
		parse->temp = ft_strjoin(parse->join, parse->with_spaces);
		free_two(parse->with_spaces, parse->join);
		parse->join = ft_strdup(parse->temp);
		free_two(parse->temp, parse->line);
		parse->line = get_next_line(fd);
	}
	parse->map = ft_strdup(parse->join);
	free(parse->join);
	if (check_duplicated_starting_position(parse) == -1)
		return (hash_destory(parse->hs), free(parse->map), -1);
	return (0);
}

int	map_parsing(t_parse *parse, char *filename)
{
	if (check_cub_extension_and_file(filename) == -1)
		return (perror("Error: file extension of the map isn't .cub"), -1);
	if (check_cub_extension_and_file(filename) == -2)
		return (perror("Error: map file doesn't exist"), -1);
	init_is_valid(parse);
	parse->fd = open(filename, O_RDONLY);
	if (init_elements(parse) == -1)
		return (perror("Erorr: invalid element on the map"), -1);
	close(parse->fd);
	if (check_walls(parse, parse->map) == -1)
		return (perror("Error: map not closed by 1"), -1);
	parse->f = hash_grep(parse->hs, "F");
	if (check_colors_f(parse) == -1)
		return (perror("Error: not a valid color in F"),
			hash_destory(parse->hs), free(parse->map), -1);
	parse->c = hash_grep(parse->hs, "C");
	if (check_colors_c(parse) == -1)
		return (perror("Error: not a valid color in C"),
			hash_destory(parse->hs), free(parse->map), -1);
	return (0);
}
