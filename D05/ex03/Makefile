# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 19:29:18 by fkoehler          #+#    #+#              #
#    Updated: 2018/01/16 18:47:08 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	Bureaucrat.cpp \
	Form.cpp \
	Intern.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = intern

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