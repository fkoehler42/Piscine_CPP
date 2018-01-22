/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:49:59 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:05:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

//// Constructors / Destructor ////

AForm::AForm(void) : _name(""), _signGrade(1), _execGrade(1), _isSigned(false) { return; }

AForm::AForm(std::string const name, int const signGrade, int const execGrade) :
_name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
	try {
		if (signGrade > 150 || execGrade > 150)
			throw AForm::GradeTooLowException();
		else if (signGrade < 1 || execGrade < 1)
			throw AForm::GradeTooHighException();
	} catch (std::exception const &err) {
		std::cout << "form " << this->getName() << " : " << err.what() << std::endl;
	}
	return;
}

AForm::AForm(AForm const &src) : _name(src.getName()), _signGrade(src.getSignGrade()),
_execGrade(src.getExecGrade()) { *this = src; }

AForm::~AForm(void) { return; }

//// Accessors ////

std::string const	&AForm::getName(void) const { return this->_name; }
int const			&AForm::getSignGrade(void) const { return this->_signGrade; }
int const			&AForm::getExecGrade(void) const { return this->_execGrade; }
bool				AForm::getIsSigned(void) const { return this->_isSigned; }

////  Class specific ////

void				AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

void				AForm::checkExecution(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	else if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	return;
}

//// Operator overloads ////

AForm		&AForm::operator=(AForm const &rhs) {
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, AForm const &rhs) {
	std::string	isSigned = rhs.getIsSigned() ? "yes" : "no";
	
	os << rhs.getName() << " form, grade to sign : " << rhs.getSignGrade() <<
	", grade to execute : " << rhs.getExecGrade() << ", already signed : " << isSigned;
	return (os);
}


//// EXCEPTIONS ////

AForm::GradeTooHighException::GradeTooHighException(void) throw() { return; }
AForm::GradeTooHighException::GradeTooHighException(GradeTooHighException const &src) throw() { *this = src; }
AForm::GradeTooHighException::~GradeTooHighException(void) throw() { return; }
AForm::GradeTooHighException	&AForm::GradeTooHighException::operator=(GradeTooHighException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*AForm::GradeTooHighException::what(void) const throw() { return ("Grade is too high."); }

AForm::GradeTooLowException::GradeTooLowException(void) throw() { return; }
AForm::GradeTooLowException::GradeTooLowException(GradeTooLowException const &src) throw() { *this = src; }
AForm::GradeTooLowException::~GradeTooLowException(void) throw() { return; }
AForm::GradeTooLowException	&AForm::GradeTooLowException::operator=(GradeTooLowException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*AForm::GradeTooLowException::what(void) const throw() { return ("Grade is too low."); }

AForm::NotSignedException::NotSignedException(void) throw() { return; }
AForm::NotSignedException::NotSignedException(NotSignedException const &src) throw() { *this = src; }
AForm::NotSignedException::~NotSignedException(void) throw() { return; }
AForm::NotSignedException	&AForm::NotSignedException::operator=(NotSignedException const &rhs) {
	(void)rhs;
	return (*this);
}
const char	*AForm::NotSignedException::what(void) const throw() { return ("Form is not signed."); }
