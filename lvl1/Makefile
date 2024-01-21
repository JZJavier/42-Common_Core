# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 18:09:36 by jjuarez-          #+#    #+#              #
#    Updated: 2024/01/21 12:43:17 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME      = libftprintf.a
CC        = cc
AR        = ar
CFLAGS    = -Wall -Wextra -Werror
ARFLAGS   = -rcs

SOURCES   = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_hexa.c ft_ptr.c  

OBJECTS = $(SOURCES:.c=.o) 

$(NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
all: ${NAME}

re: fclean all

.PHONY: all clean fclean re
