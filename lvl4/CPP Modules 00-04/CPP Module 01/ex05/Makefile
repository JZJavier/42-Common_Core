# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 08:08:51 by jjuarez-          #+#    #+#              #
#    Updated: 2024/05/18 08:06:17 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= harl
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRC			= main.cpp Harl.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re