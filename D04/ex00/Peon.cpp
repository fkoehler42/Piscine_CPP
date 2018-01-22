/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:44:00 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:14:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Peon.hpp"


Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src.getName()) {
	*this = src;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void) { 
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(void) : Victim("") {}

Peon		&Peon::operator=(Peon const &rhs) {
	this->setName(rhs.getName());
	return (*this);
}

void			Peon::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Peon const &rhs) {
	os << rhs.introduce();
	return (os);
}