# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 19:29:18 by fkoehler          #+#    #+#              #
#    Updated: 2017/12/18 19:30:58 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CC = clang++
FLAGS = -Wall -Wextra -Werror

NAME = phoneBook

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

$(OBJ)%.o: %.cpp
	@$(CC) $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[0;34m$(NAME) object files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;34m$(NAME) executable deleted !\033[0;m"

re: fclean all

.PHONY: all clean fclean re
