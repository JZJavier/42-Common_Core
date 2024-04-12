/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:40:59 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/10 21:30:54 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

char	*add_space(t_parse *parse, char *line)
{
	int		line_len;
	int		i;
	char	*new_line;

	line_len = ft_strlen(line);
	i = 0;
	new_line = malloc (parse->width + 1);
	while (i < line_len)
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < parse->width - 1)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	free_three(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

void	free_two(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void	free_two_and_hash(t_parse *parse, char *s1, char *s2)
{
	free(s1);
	free(s2);
	hash_destory(parse->hs);
}

void	free_three_hsh(t_parse *parse, char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
	hash_destory(parse->hs);
}
