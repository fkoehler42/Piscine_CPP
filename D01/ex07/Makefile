# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 10:14:44 by fkoehler          #+#    #+#              #
#    Updated: 2018/01/10 11:58:25 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

CC = clang++
FLAGS = -Wall -Wextra -Werror

NAME = replace

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
	@rm -f $(NAME) *.replace
	@echo "\033[0;34m$(NAME) executable and output files deleted !\033[0;m"
	@echo "\033[0;34m".replace" output files deleted !\033[0;m"

re: fclean all

.PHONY: all clean fclean re
