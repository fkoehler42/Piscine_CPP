/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blob.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:44:00 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:14:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Blob.hpp"

Blob::Blob(std::string name) : Victim(name) {
	std::cout << "Blob here !" << std::endl;
}

Blob::Blob(Blob const &src) : Victim(src.getName()) {
	*this = src;
	std::cout << "Blob here !" << std::endl;
}

Blob::~Blob(void) { 
	std::cout << "Nooooooo !" << std::endl;
}

Blob::Blob(void) : Victim("") {}

Blob		&Blob::operator=(Blob const &rhs) {
	this->setName(rhs.getName());
	return (*this);
}

void			Blob::getPolymorphed(void) const {
	std::cout << this->getName() << " has been turned into a dirty shit !" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Blob const &rhs) {
	os << rhs.introduce();
	return (os);
}