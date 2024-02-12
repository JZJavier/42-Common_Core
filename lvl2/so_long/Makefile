# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 21:53:52 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/12 20:18:01 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Imlx -Ilibft -c
RM          = rm -rf
MLXFLAGS    = -Lmlx -lmlx -framework OpenGL -framework AppKit
SOURCES     = src/main.c src/map_read.c
LIBFT       = libft/libft.a

OBJECTS     = $(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJECTS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
