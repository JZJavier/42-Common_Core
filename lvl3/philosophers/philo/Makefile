# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 20:20:46 by jjuarez-          #+#    #+#              #
#    Updated: 2024/03/31 22:51:45 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= cc
CFLAGS	= -Werror -Wall -Wextra -g3 -fsanitize=thread
SRCS	= main.c parse.c init.c routine.c ft_time.c utils/ft_atoi.c utils/ft_atol.c utils/write.c
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