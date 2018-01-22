/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/15 19:50:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

//// CONSTRUCT / DESTRUCT ////

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) { return; }

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) { this->setGrade(grade); }

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()) { *this = src; }

Bureaucrat::~Bureaucrat(void) { return; }

//// ACCESSORS ////

std::string const	Bureaucrat::getName(void) const{ return this->_name; }
int					Bureaucrat::getGrade(void) const{ return this->_grade; }

void				Bureaucrat::setGrade(int grade) {
	try {
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade = grade;
	}
	catch (std::exception &err) {
		std::cout << "Bureaucrat " << this->getName() << " : " << err.what() << std::endl;
	}
}

//// CLASS SPECIFIC ////

void				Bureaucrat::incrementGrade(void) { this->setGrade(this->getGrade() - 1); }
void				Bureaucrat::decrementGrade(void) { this->setGrade(this->getGrade() + 1); }

void				Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName()	<< " form." << std::endl;
	}
	catch (std::exception &err) {
		std::cout << this->getName() << " can't signs " << form.getName()
		<< "form. Reason : " << err.what() << std::endl;
	}
}

//// OPERATORS OVERLOAD ////

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &rhs) {
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream		&operator<<(std::ostream &os, Bureaucrat const &rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}

//// EXCEPTIONS ////

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw() { return; }
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw() { *this = src; }
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() { return; }
Bureaucrat::GradeTooHighException	&Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Grade is too high."); }

Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw() { return; }
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw() { *this = src; }
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() { return; }
Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Grade is too Low."); }