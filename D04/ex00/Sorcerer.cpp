/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:44:00 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 19:15:57 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"


Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
	*this = src;
	std::cout << this->getName() << ", " << this->getTitle() << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer(void) { 
	std::cout << this->getName() << ", " << this->getTitle() <<
	", is dead . Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(void) {}

Sorcerer		&Sorcerer::operator=(Sorcerer const &rhs) {
	this->setName(rhs.getName());
	this->setTitle(rhs.getTitle());
	return (*this);
}

std::string		Sorcerer::getName(void) const { return (this->_name); }
std::string		Sorcerer::getTitle(void) const { return (this->_title); }

void			Sorcerer::setName(std::string name) { this->_name = name; }
void			Sorcerer::setTitle(std::string title) { this->_title = title; }

std::string		Sorcerer::introduce(void) const {
	std::string intro;

	intro = "I am " + this->getName() + ", " + this->getTitle()
	+ ", and I like ponies ! (but not C++)\n";
	return (intro);
}

void			Sorcerer::polymorph(Victim const &victim) const { victim.getPolymorphed(); }

std::ostream	&operator<<(std::ostream &os, Sorcerer const &rhs) {
	os << rhs.introduce();
	return (os);
}