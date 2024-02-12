/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:43:57 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/12 20:57:21 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *filename)
{
	char *extension;

	extension = ft_strrchr(filename, '.');
	if (ft_strcmp(extension, ".ber") == 0)
		return (1);
	return (0);
}

int check_map_file_exist(char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close (fd); // Ver si hay que cerrarlo o mandar el fd abierto a otra función
	return (1);
}

// Crear mañana el array de arrays y comprobar todos los requisitos que tiene que cumplir el mapa
// Se tiene que hacer con get_next_line y una vez haya leido todo el mapa hacer un spplit de la linea
// por los \n 
// ver como hacer para que guarde el mapa completo en un char * para despues poder dividirlo
// Hacer como minimo el casteo

char **map_read(char *filename)
{
	if (check_ber_extension(filename) == 0)
		perror ("Error: file extension of the map isn't .ber"); //Ver si tengo que liberar algo.
	if (check_map_file_exist(filename) == 0)
		perror ("Error: map file doesn't exist on maps folder"); //Ver si tengo que liberar algo.
	return (NULL);
}