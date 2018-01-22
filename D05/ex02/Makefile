# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 19:29:18 by fkoehler          #+#    #+#              #
#    Updated: 2018/01/16 17:08:22 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	Bureaucrat.cpp \
	Form.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = forms

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

clean:
	@rm -f $(NAME)
	@echo "\033[0;34m$(NAME) executable deleted !\033[0;m"

fclean: clean
	@rm -f *_shrubbery
	@echo "\033[0;34mShruberry generated files deleted !\033[0;m"

re: fclean all

.PHONY: all clean fclean re