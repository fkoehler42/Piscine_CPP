/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 14:51:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/time.h>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);this->_log();
	std::cout << "Ha ha ha ! I LIVE !(default)." << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const name) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	this->setName(name);
	this->setMaxHitPoints(100);
	this->setHitPoints(100);
	this->setMaxEnergyPoints(50);
	this->setEnergyPoints(50);
	this->setLevel(1);
	this->setMeleeAttackDmg(20);
	this->setRangedAttackDmg(15);
	this->setArmorDmgReduction(3);
	this->_log();
	std::cout << "Ha ha ha ! I LIVE !(param)." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	*this = src;
	this->_log();
	std::cout << "Ha ha ha ! I LIVE !(copy)." << std::endl;
	return;
}

ScavTrap::~ScavTrap(void) {
	this->_log();
	std::cout << "I'm too pretty to die..." << std::endl;
	return;
}

ScavTrap		&ScavTrap::operator=(ScavTrap const &rhs) {
	this->setHitPoints(rhs.getHitPoints());
	this->setMaxHitPoints(rhs.getMaxHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setMaxEnergyPoints(rhs.getMaxEnergyPoints());
	this->setLevel(rhs.getLevel());
	this->setMeleeAttackDmg(rhs.getMeleeAttackDmg());
	this->setRangedAttackDmg(rhs.getRangedAttackDmg());
	this->setArmorDmgReduction(rhs.getArmorDmgReduction());
	this->setName(rhs.getName());
	return (*this);
}

void			ScavTrap::challengeNewComer(std::string const & target) {
	int	randIndex = 0;

	this->_log();
		while (ScavTrap::_challenges[randIndex] != "")
			randIndex++;
		randIndex = rand() % randIndex;
		std::cout << "You versus me ! Me versus you ! Either way ! - Issues a " <<
		ScavTrap::_challenges[randIndex] << " challenge to " << target << '.' << std::endl;
}


void			ScavTrap::_log(void) const {
	std::cout << "SC4V-TP (" << this->getName() << ") - ";	
}

std::string const	ScavTrap::_challenges[] = { "dancing battle", "step climbing", "wasabi eating", "say anything", "oil drinking" };