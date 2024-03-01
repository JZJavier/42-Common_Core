# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 21:36:28 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/29 22:34:47 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Werror -Wall -Wextra -pthread -fsanitize=address -g
SRCS	= 	src/main.c src/time.c src/init.c src/routine.c src/parsing.c \
		src/error.c src/free.c src/end.c src/print.c src/time_to.c \
		src/total_meals.c src/take_forks.c src/drop_forks.c \
		src/utils/ft_atoi.c src/utils/ft_isspace.c src/utils/ft_strlen.c \
		src/utils/ft_isdigit.c
RM		= rm -rf
OBJECTS		= ${SRCS:.c=.o}

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o ${NAME}

all: $(NAME)

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re