# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 08:16:21 by jjuarez-          #+#    #+#              #
#    Updated: 2024/03/21 14:49:20 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -rf
LIBFT		= Libft/libft.a
INCLUDE		= ./include/

PIPEX		= error.c free.c
HASH		= hash_list.c hash_utils.c hash.c arr_utils.c arr_utils2.c
MANDATORY	= main.c open.c init.c close.c pipex.c
BONUS		= main_bonus.c open_bonus.c init_bonus.c close_bonus.c pipex_bonus.c here_doc.c

SRCS		= $(addprefix ./src/mandatory/, $(MANDATORY)) $(addprefix ./src/, $(PIPEX)) $(addprefix ./src/hash_map/, $(HASH))
SRCS_BONUS	= $(addprefix ./src/bonus/, $(BONUS)) $(addprefix ./src/, $(PIPEX)) $(addprefix ./src/hash_map/, $(HASH))

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -Llibft -lft -o $(NAME)


all : $(NAME)

clean :
	$(RM) $(NAME)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

bonus:
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) -Llibft -lft -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus