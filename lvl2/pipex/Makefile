# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 09:40:51 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/12 12:03:41 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	pipex.c pipex_utils.c libft/libft.a

SRCS_BONUS = bonus/pipex_bonus.c bonus/pipex_utils_bonus.c libft/libft.a

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

clean :
	$(RM) $(NAME)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

bonus: clean
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

re : fclean all
