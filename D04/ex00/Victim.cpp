/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:44:00 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:14:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"


Victim::Victim(std::string name) : _name(name) {
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;
}

Victim::Victim(Victim const &src) {
	*this = src;
	std::cout << "Some random victim called " << this->getName() << " just popped !" << std::endl;
}

Victim::~Victim(void) { 
	std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(void) {}

Victim		&Victim::operator=(Victim const &rhs) {
	this->setName(rhs.getName());
	return (*this);
}

std::string		Victim::getName(void) const { return (this->_name); }

void			Victim::setName(std::string name) { this->_name = name; }

std::string		Victim::introduce(void) const {
	std::string intro;

	intro = "I am " + this->getName() + " and I like otters !\n";
	return (intro);
}

void			Victim::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Victim const &rhs) {
	os << rhs.introduce();
	return (os);
}