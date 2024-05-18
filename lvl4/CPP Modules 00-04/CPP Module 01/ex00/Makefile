# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 08:08:51 by jjuarez-          #+#    #+#              #
#    Updated: 2024/05/17 08:38:46 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= zombie
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g
RM			= rm -f

SRC			= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 
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