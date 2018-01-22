/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:38:22 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:05:20 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//// Constructors / Destructor ////

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("", 72, 45) {
	srand(time(NULL));
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const name) : AForm(name, 72, 45) {
	srand(time(NULL));
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
	srand(time(NULL));
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void) { return; }

//// Class specific ////

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	try {
		this->checkExecution(executor);
		std::cout << "*brrrr* ";
		if (rand() % 2 == 1)
			std::cout << executor.getName() << " has been robotomized successfully !" << std::endl;
		else
			std::cout << "Robotomization of " << executor.getName() << " has failed..." << std::endl;
	} catch (std::exception const &ex) { throw; }
}

//// Operator overloads ////

RobotomyRequestForm		&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	AForm::operator=(rhs);
	return (*this);
}