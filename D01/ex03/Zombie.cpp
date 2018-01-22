/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:04:40 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:34:27 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sys/time.h>
#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::string	randName;
	std::string	randType;

	this->_setName(Zombie::_getRandName());
	this->_setType(Zombie::_getRandType());
	std::cout << "A new zombie has joined the horde (" << this->_name << " the "
	<< this->_type << ")" << std::endl;
	return;
}

Zombie::~Zombie(void) {	std::cout << "A zombie has been destroyed" << std::endl; }

void		Zombie::announce(void) {
	std::cout << '<' << this->getName() << " (" << this->getType()
	<< ")> Braiiiiiiinnnsss..." << std::endl;
}

std::string	Zombie::getName(void) { return (this->_name); }
std::string	Zombie::getType(void) { return (this->_type); }

void		Zombie::_setName(std::string name) { this->_name = name; }
void		Zombie::_setType(std::string type) { this->_type = type; }

std::string	Zombie::_getRandName(void) {
	int		i = 0;
	int		randIndex;
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	while (Zombie::_names[i] != "")
		i++;
	randIndex = rand() % i;
	return (Zombie::_names[randIndex]);
}

std::string	Zombie::_getRandType(void) {
	int		i = 0;
	int		randIndex;
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	while (Zombie::_types[i] != "")
		i++;
	randIndex = rand() % i;
	return (Zombie::_types[randIndex]);
}

std::string	Zombie::_names[] = { "Rick", "Carl", "Michonne", "Daryl", "Glenn", "Maggie", "Negan", "Judith", "Tyreese" };
std::string	Zombie::_types[] = { "Biter", "Walker", "Sleeper", "Screamer", "Stalker", "Rapist" };