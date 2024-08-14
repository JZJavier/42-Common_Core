NAME = webserv

SRC_DIR = ./src
INCLUDE_DIR = ./include
OBJ_DIR = ./obj


CPPFILES = main.cpp Config.cpp Server.cpp RequestHandler.cpp HttpRequest.cpp HttpResponse.cpp ParserURL.cpp Cgi.cpp src/SessionManager.cpp
CPPFILES := $(addprefix $(SRC_DIR)/, $(CPPFILES))
OFILES = $(addprefix $(OBJ_DIR)/, $(notdir $(CPPFILES:.cpp=.o)))

CPPFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE_DIR)

all: $(NAME)

$(NAME): $(OFILES)
	c++ $(CPPFLAGS) -o $(NAME) $(OFILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	c++ $(CPPFLAGS) -c -Wshadow $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OFILES)
	$(RM) -r $(OBJ_DIR)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
