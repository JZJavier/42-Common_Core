# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 10:54:05 by jjuarez-          #+#    #+#              #
#    Updated: 2024/04/20 17:53:00 by jjuarez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook
CXX			= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRC			= Contact.cpp Phonebook.cpp
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