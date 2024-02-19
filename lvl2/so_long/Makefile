# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 21:53:52 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/19 00:35:56 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Imlx -Ilibft -c -g3
RM			= rm -rf
MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit
SOURCES		= src/main.c src/map_validate.c src/map_parsing.c src/map_init.c \
			src/check_path.c src/events.c src/print.c src/window.c src/free.c
BONUS		= src/bonus/main_bonus.c src/bonus/map_validate_bonus.c src/bonus/map_parsing_bonus.c \
			 src/bonus/map_init_bonus.c src/bonus/check_path_bonus.c src/bonus/events_bonus.c \
			 src/bonus/print_bonus.c src/bonus/window_bonus.c src/bonus/free_bonus.c
LIBFT		= Libft/libft.a

OBJECTS     = $(SOURCES:%.c=%.o)
BONUS_OBJS = $(BONUS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

all : $(NAME)

bonus: $(BONUS_OBJS)
	@make -C libft
	@$(CC) $(BONUS_OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

re: fclean all

.PHONY: all clean fclean re
