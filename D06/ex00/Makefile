# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 19:29:18 by fkoehler          #+#    #+#              #
#    Updated: 2018/01/17 13:53:26 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	Scalar.cpp

CC = clang++
FLAGS = -Wall -Wextra -Werror

NAME = convert

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

clean:
	@rm -f $(NAME)
	@echo "\033[0;34m$(NAME) executable deleted !\033[0;m"

fclean: clean

re: fclean all

.PHONY: all clean fclean re
