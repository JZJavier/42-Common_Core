/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:11:39 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 00:39:01 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_error(char *error, t_map *map)
{
	ft_printf("%s%s", error);
	if (map->status == 1)
		free_matrice(map);
	exit(EXIT_FAILURE);
}

void	free_matrice(t_map *map)
{
	int	i;

	i = 0;
	if (map->matrice)
	{
		while (map->matrice[i])
		{
			free(map->matrice[i]);
			i++;
		}
		free(map->matrice);
	}
}
