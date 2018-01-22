/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:04:40 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:39:03 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) : _name(""), _type("") {
	std::cout << "New zombie created" << std::endl;
	return;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie deleted" << std::endl;
	return;
}

void		Zombie::announce(void) {
	std::cout << '<' << this->getName() << " (" << this->getType()
	<< ")> Braiiiiiiinnnsss..." << std::endl;
}

std::string	Zombie::getName(void) { return (this->_name); }
std::string	Zombie::getType(void) { return (this->_type); }

void		Zombie::setName(std::string name) {	this->_name = name; }
void		Zombie::setType(std::string type) {	this->_type = type; }

std::string	Zombie::names[] = { "Rick", "Carl", "Michonne", "Daryl", "Glenn", "Maggie", "Negan", "Judith", "Tyreese" };
std::string	Zombie::types[] = { "Biter", "Walker", "Sleeper", "Screamer", "Stalker", "Rapist" };
