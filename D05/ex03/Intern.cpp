/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:34:36 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 18:39:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//// Constructors / Destructor ////

Intern::Intern(void) { return; }

Intern::Intern(Intern const &src) { *this = src; }

Intern::~Intern(void) { return; }


//// Class Specific ////

AForm	*Intern::makeForm(std::string const formType, std::string const formName) const {
	AForm		*newForm = NULL;

	try {
		if (formType == "robotomyrequest" || formType == "robotomy request")
			newForm = new RobotomyRequestForm(formName);
		else if (formType == "shrubberycreation" || formType == "shrubbery creation")
			newForm = new ShrubberyCreationForm(formName);
		else if (formType == "presidentialpardon" || formType == "presidential pardon")
			newForm = new PresidentialPardonForm(formName);
		else
			throw Intern::UnknownFormException();
		std::cout << "Intern creates " << formName << " form. (" << formType << ')' << std::endl;
	} catch (std::exception const &ex) {
		std::cout << "Intern can't make a new form. Reason : " << ex.what() << std::endl;
	}
	return (newForm);
}

//// Operators Overloads ////

Intern		&Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return (*this);
}

//// Exceptions ////

Intern::UnknownFormException::UnknownFormException(void) throw() { return; }
Intern::UnknownFormException::UnknownFormException(UnknownFormException const &src) throw() { *this = src; }
Intern::UnknownFormException::~UnknownFormException(void) throw() { return; }
Intern::UnknownFormException	&Intern::UnknownFormException::operator=(UnknownFormException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*Intern::UnknownFormException::what(void) const throw() { return ("Unknown form."); }