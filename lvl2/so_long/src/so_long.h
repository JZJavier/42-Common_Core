/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:16:45 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/12 16:31:34 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
#define SO_LONG_H

// Includes
# include "../Libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// Map representation
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

// Map resolution

# define WIDTH 1920
# define HEIGHT 1080

//Falta t_map

typedef struct s_data
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*textures[5]; // MLX image pointers (on the stack)
	//t_map	*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;

// Functions
// Map_read
char	**map_read(char *filename);


#endif