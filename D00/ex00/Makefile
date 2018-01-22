# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 17:32:19 by fkoehler          #+#    #+#              #
#    Updated: 2017/12/18 18:05:45 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

CC = clang++
FLAGS = -Wall -Wextra -Werror

NAME = megaphone

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

$(OBJ)%.o: %.cpp
	@$(CC) $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[0;34m$(OBJ) deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;34m$(NAME) executable deleted !\033[0;m"

re: fclean all

.PHONY: all clean fclean re
