/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:38:22 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:15:41 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//// Constructors / Destructor ////

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("", 25, 5) { return; }

PresidentialPardonForm::PresidentialPardonForm(std::string const name) : AForm(name, 25, 5) { return; }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) {	*this = src; }

PresidentialPardonForm::~PresidentialPardonForm(void) { return; }

//// Class specific ////

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	try {
		this->checkExecution(executor);
		std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	} catch (std::exception const &ex) { throw; }
}

//// Operator overloads ////

PresidentialPardonForm		&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	AForm::operator=(rhs);
	return (*this);
}