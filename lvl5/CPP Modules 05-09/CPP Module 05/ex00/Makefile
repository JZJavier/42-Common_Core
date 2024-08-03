# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javier <javier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 08:08:51 by jjuarez-          #+#    #+#              #
#    Updated: 2024/08/02 17:37:12 by javier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 #-g
RM			= rm -f

SRC			= main.cpp BAForm::execute(executor);AForm::execute(executor);ureaucrat.cpp
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