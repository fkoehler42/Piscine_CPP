/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:49:59 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/15 19:54:19 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

//// Constructors / Destructor ////

Form::Form(void) : _name(""), _signGrade(1), _execGrade(1), _isSigned(false) { return; }

Form::Form(std::string const name, int const signGrade, int const execGrade) :
_name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
	try {
		if (signGrade > 150 || execGrade > 150)
			throw Form::GradeTooLowException();
		else if (signGrade < 1 || execGrade < 1)
			throw Form::GradeTooHighException();
	} catch (std::exception &err) {
		std::cout << "Form " << this->getName() << " : " << err.what() << std::endl;
	}
	return;
}

Form::Form(Form const &src) : _name(src.getName()), _signGrade(src.getSignGrade()),
_execGrade(src.getExecGrade()) { *this = src; }

Form::~Form(void) { return; }

//// Accessors ////

std::string const	&Form::getName(void) const { return this->_name; }
int const			&Form::getSignGrade(void) const { return this->_signGrade; }
int const			&Form::getExecGrade(void) const { return this->_execGrade; }
bool				Form::getIsSigned(void) const { return this->_isSigned; }

////  Class specific ////

void				Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

//// Operator overloads ////

Form		&Form::operator=(Form const &rhs) {
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Form const &rhs) {
	std::string	isSigned = rhs.getIsSigned() ? "yes" : "no";
	
	os << rhs.getName() << " form, grade to sign : " << rhs.getSignGrade() <<
	", grade to execute : " << rhs.getExecGrade() << ", already signed : " << isSigned;
	return (os);
}


//// EXCEPTIONS ////

Form::GradeTooHighException::GradeTooHighException(void) throw() { return; }
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw() { *this = src; }
Form::GradeTooHighException::~GradeTooHighException(void) throw() { return; }
Form::GradeTooHighException	&Form::GradeTooHighException::operator=(GradeTooHighException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*Form::GradeTooHighException::what(void) const throw() { return ("Grade is too high."); }

Form::GradeTooLowException::GradeTooLowException(void) throw() { return; }
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw() { *this = src; }
Form::GradeTooLowException::~GradeTooLowException(void) throw() { return; }
Form::GradeTooLowException	&Form::GradeTooLowException::operator=(GradeTooLowException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*Form::GradeTooLowException::what(void) const throw() { return ("Grade is too Low."); }
