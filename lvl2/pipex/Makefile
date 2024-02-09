# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 09:40:51 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/09 05:44:06 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

variable = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	pipex.c pipex_utils.c libft/libft.a


$(variable) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(variable)


all : $(variable)

fclean : clean
	$(RM) $(variable)
	make fclean -C libft

clean :
	$(RM) $(variable)
	make clean -C libft

re : fclean all

