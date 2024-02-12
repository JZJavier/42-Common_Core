/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:05:18 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/12 20:48:08 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int main(int argc, char **argv)
{
	t_data data;
	int i = 0;
	if (argc == 2)
	{
		while (argv[i]) //BORRRAR
			i++; //BORRAR
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1); // Ver si mandar mensaje
		data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "jjuarez-'s SO_LONG");
		if (!data.win_ptr)
			return (free(data.mlx_ptr), 1); // Ver si mandar menaje
		map_read(argv[1]);
		mlx_loop(data.mlx_ptr);
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		//To avoid leaks
		//mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
	else
		return (1); //Ver si hay que mandar mensaje como por ejemplo falta el mapa o elija el mapa
	return(0);
}*/

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		map_read(argv[1]);
	}
	else
		perror("Error: ./so_long map: a valid path to the map is missing");
	system("leaks -q so_long");
	return(0);
}