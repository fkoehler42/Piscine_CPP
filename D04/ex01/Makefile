# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 19:29:18 by fkoehler          #+#    #+#              #
#    Updated: 2018/01/12 22:03:12 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	AWeapon.cpp \
	PlasmaRifle.cpp \
	PowerFist.cpp \
	Enemy.cpp \
	SuperMutant.cpp \
	RadScorpion.cpp \
	Character.cpp

CC = clang++
FLAGS = -Wall -Wextra -Werror

NAME = warzone

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

clean:
	@rm -f $(OBJ)
	@echo "\033[0;34m$(NAME) object files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;34m$(NAME) executable deleted !\033[0;m"

re: fclean all

.PHONY: all clean fclean re
