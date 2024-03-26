# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 21:53:52 by jjuarez-          #+#    #+#              #
#    Updated: 2024/03/26 18:51:17 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
MANDATORY	= push_swap.c sort_3.c parse.c error.c list_utils.c stack.c init.c find.c
ROTATIONS	= push.c pa.c pb.c reverse_rotate.c rra.c rrb.c rrr.c rotate.c ra.c rb.c rr.c swap.c sa.c sb.c ss.c

SOURCES = $(addprefix ./src/mandatory/, $(MANDATORY)) $(addprefix ./src/mandatory/rotations/, $(ROTATIONS)) src/mandatory/main.c
BONUS = $(addprefix ./src/mandatory/, $(MANDATORY)) $(addprefix ./src/mandatory/rotations/, $(ROTATIONS)) src/bonus/checker.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)

LIBFT		= Libft/libft.a
INCLUDE		= ./include/

all : $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -I $(INCLUDE) -o $(NAME)

$(LIBFT):
	make -C libft

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@ 

bonus : $(BONUS_OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -I $(INCLUDE) -o checker

clean :
	@$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	@$(RM) $(NAME) checker

re : fclean all

.PHONY : all clean fclean re bonus
