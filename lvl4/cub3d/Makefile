# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javgao <yugao@student.42madrid.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:42:20 by yugao             #+#    #+#              #
#    Updated: 2024/04/11 21:30:49 by javgao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
PARSE	= map_parsing.c dimensions.c parse_utils.c color.c
HASH	= hash_list.c hash_utils.c hash.c arr_utils.c arr_utils2.c
CFILE	= $(addprefix ./srcs/mandatory/, $(PARSE)) $(addprefix ./srcs/mandatory/hash_map/, $(HASH)) \
			$(addprefix ./srcs/mandatory/, cub_2d_bk.c cub_fix.c cub_graph_base.c cub_init2.c cub_biu_apoyo.c\
			cub_img.c cub_transfer.c cub_math2.c  cub_matrix1.c cub_biubiu.c cub_matrix2.c cub_over.c \
			cub_graph_ray.c cub_init.c cub_key.c cub_main.c cub_math1.c cub_vec.c)
BONUS	= main_bonus.c mouse_bonus.c
CBONUS	= $(addprefix ./srcs/bonus/, $(BONUS)) \
			$(addprefix ./srcs/bonus/hash_map/, hash_list.c hash_utils.c hash.c arr_utils.c arr_utils2.c) \
			$(addprefix ./srcs/bonus/, map_parsing_bonus.c dimensions_bonus.c parse_utils_bonus.c color_bonus.c \
			cub_2d_bk_bonus.c cub_fix_bonus.c cub_graph_base_bonus.c cub_init2_bonus.c cub_biu_apoyo_bonus.c cub_anime_bonus.c\
			cub_img_bonus.c cub_transfer_bonus.c cub_math2_bonus.c  cub_matrix1_bonus.c cub_biubiu_bonus.c cub_matrix2_bonus.c cub_over_bonus.c \
			cub_graph_ray_bonus.c cub_init_bonus.c cub_key_bonus.c cub_math1_bonus.c cub_vec_bonus.c walls_bonus.c)
OFILE	= $(CFILE:.c=.o)
CFLAG	= -Wall -Werror -Wextra
LDFLAGS	= -framework OpenGL -framework AppKit 
LIBS	= -L minilibx -lmlx -lz
LIBFT	= libft/libft.a
INCLUDE	= ./include/

all: $(NAME)

BONUS_OBJS = $(CBONUS:.c=.o)

$(NAME): $(OFILE) libft
	gcc $(OFILE) $(LIBFT) $(LIBS) $(LDFLAGS) -I $(INCLUDE) -o $(NAME) -v

%.o:%.c
	gcc $(CFLAG) -c -Imlx -DGL_SILENCE_DEPRECATION $< -o $@ 

libft:
	$(MAKE) -C libft

bonus: $(BONUS_OBJS)
	make -C libft
	gcc $(BONUS_OBJS) $(LIBFT) $(LIBS) $(LDFLAGS) -I $(INCLUDE) -o cub3d_bonus -v

clean:
	rm -f $(OFILE)
	rm -f $(BONUS_OBJS)
	$(MAKE) fclean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f cub3d_bonus
	$(MAKE) clean -C libft

re: fclean all

.PHONY: fclean clean libft
