# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 18:09:36 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/16 17:54:59 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libft.a
CC        = cc
AR        = ar
CFLAGS    = -Wall -Wextra -Werror
ARFLAGS   = -rcs
PRINTF    = ft_printf/libftprintf.a

SOURCES   = ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c \
            ft_strmapi.c ft_strtrim.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c \
            ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_bzero.c \
            ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c \
            ft_strnstr.c ft_tolower.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memset.c \
            ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_strcmp.c \
			get_next_line_utils_bonus.c get_next_line_bonus.c ft_strchrlen.c ft_strcountchars.c \

BONUS = 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJECTS = $(SOURCES:.c=.o) 
BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJECTS) $(PRINTF)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(PRINTF):
	make -C ft_printf

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ft_printf

all: ${NAME}

re: fclean all

bonus: $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re
