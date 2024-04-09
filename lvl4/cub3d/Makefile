# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:42:20 by yugao             #+#    #+#              #
#    Updated: 2024/04/09 00:40:46 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
PARSE	= map_parsing.c dimensions.c parse_utils.c color.c
HASH	= hash_list.c hash_utils.c hash.c arr_utils.c arr_utils2.c
CFILE	= $(addprefix ./srcs/, $(PARSE)) $(addprefix ./srcs/hash_map/, $(HASH)) \
			$(addprefix ./srcs/, cub_2d_bk.c cub_fix.c cub_graph_base.c cub_init2.c cub_biu_apoyo.c\
			cub_img.c cub_transfer.c cub_math2.c  cub_matrix1.c cub_biubiu.c cub_matrix2.c cub_over.c \
			cub_graph_ray.c cub_init.c cub_key.c cub_main.c cub_math1.c cub_vec.c)
			
OFILE	= $(CFILE:.c=.o)
CFLAG	= -Wall -Werror -Wextra
LDFLAGS	= -framework OpenGL -framework AppKit 
LIBS	= -L minilibx -lmlx -lz
LIBFT	= libft/libft.a
INCLUDE	= ./include/

all: $(NAME)

$(NAME): $(OFILE) libft
	gcc $(OFILE) $(LIBFT) $(LIBS) $(LDFLAGS) -I $(INCLUDE) -o $(NAME) -v

%.o:%.c
	gcc $(CFLAG) -c -Imlx -DGL_SILENCE_DEPRECATION $< -o $@ 

libft:
	$(MAKE) -C libft

clean:
	rm -f $(OFILE)
	$(MAKE) fclean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C libft

re: fclean all

.PHONY: fclean clean libft
