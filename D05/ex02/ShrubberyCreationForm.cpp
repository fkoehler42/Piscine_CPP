/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:38:22 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 16:01:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//// Constructors / Destructor ////

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("", 145, 137) { return; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const name) : AForm(name, 145, 137) { return; }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) { *this = src; }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { return; }

//// Class specific ////

void		ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	std::ofstream	ofs;

	try {
		this->checkExecution(executor);
		ofs.open(executor.getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
		ofs << "               ,@@@@@@@,\n       ,,,.   ,@@@@@@/@@,  .oo8888o.\n    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n   ,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n   `&%\\ ` /%&'    |.|        \\ '|8'\n       |o|        | |         | |\n       |.|        | |         | |\n    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
		ofs.close();
	} catch (std::exception const &ex) { throw; }
}

//// Operator overloads ////

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	AForm::operator=(rhs);
	return (*this);
}