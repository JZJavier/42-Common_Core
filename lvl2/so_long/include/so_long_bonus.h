/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:00:59 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/19 01:09:56 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 13
# define ESC 53
# define FILESIZE 40960

# define ENEMY "./sprites/Enemy.xpm"
# define PLAYER_DOWN "./sprites/Player.xpm"
# define PLAYER_LEFT "./sprites/Player_Left.xpm"
# define PLAYER_RIGHT "./sprites/Player_Right.xpm"
# define PLAYER_UP "./sprites/Player_Up.xpm"
# define COLLECTIBLE "./sprites/Collectible.xpm"
# define EXIT "./sprites/Exit.xpm"
# define WALL "./sprites/Wall.xpm"
# define FLOOR "./sprites/Floor.xpm"

typedef struct s_map
{
	char	*dir;
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_height;
	int		map_width;
	int		collectible;
	int		collectible_copy;
	int		exit;
	int		moves;
	int		player;
	int		position_y;
	int		position_x;
	int		status;
	int		img_width;
	int		img_height;
	void	*img;
	void	*img_player;
	void	*img_collectible;
	void	*img_floor;
	void	*img_exit;
	void	*img_wall;
	void	*img_enemy;
	char	**matrice;
	char	**matrice_copy;
}	t_map;

//Main.c
int		main(int argc, char *argv[]);
void	init_struct(t_map *map);

// Map_init
char	*map_one_str(char	*filename);
void	get_dimensions(t_map *map);
void	map_matrice(t_map *map, char *filename);

//Map validate
int		map_parsing(char *filename);
int		check_walls(char *filename);
int		check_floor_top(char *filename);
int		map_validate(char *filename);

//Map_parsing
int		check_ber_extension_and_file(char *filename);
int		check_invalid_characters(char *filename);
int		check_minimum_characters(char *filename);
int		check_rectangle(char *filename);
int		check_line_len(char *filename);

// Exit
void	perror_and_exit(char *error);

//Check Path
void	count_collectible(t_map *map);

//Window
void	init_xpm(t_map *map);
int		open_window(t_map *map);

//Print
void	print_floor(t_map *map);
void	draw_img(int y, int x, t_map *map);
void	print_map(t_map *map);
void	choose_player(t_map *map, int y, int x);

//Check_path
void	check_path(t_map *map, int x, int y);
void	check_and_free(t_map *map);

//Free
void	free_matrice(t_map *map);
int		ft_error(char *error, t_map *map);

//Events
void	print_moves_screen(t_map *map);
int		detect_key(int key, t_map *map);
int		handle_movement(int key, t_map *map);
int		check_win_condition(t_map *map);
void	move_player(t_map *map, int y, int x);

#endif
