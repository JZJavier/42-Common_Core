# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 07:14:59 by jjuarez-          #+#    #+#              #
#    Updated: 2024/02/22 09:56:37 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= src/main.c src/radix_sort.c src/small_numbers.c src/index.c src/check_args.c \
			src/list/ft_lstsize.c src/list/ft_lstadd_back.c src/error.c src/ft_check_sorted.c \
			src/free.c src/ft_create_stack.c src/get_distance.c src/operations/pa.c src/operations/pb.c \
			src/operations/push.c src/operations/ra.c src/operations/rb.c src/operations/reverserotate.c \
			src/operations/rotate.c src/operations/rr.c src/operations/rra.c src/operations/rrb.c src/operations/rrr.c \
			src/operations/sa.c src/operations/sb.c src/operations/ss.c src/operations/swap.c src/list/ft_lstadd_front.c \
			src/list/ft_lstlast.c src/list/ft_lstnew.c src/sort_3.c
RM			= rm -rf
LIBFT		= Libft/libft.a
OBJECTS		= ${SRCS:.c=.o}


$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o ${NAME}

all: $(NAME)

clean: 
	@$(RM) $(OBJECTS)
	make clean -C Libft

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
