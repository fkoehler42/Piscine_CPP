/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 14:51:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/time.h>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);this->_log();
	std::cout << "Start bootup sequence(default)." << std::endl;
	return;
}

FragTrap::FragTrap(std::string const name) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	this->setName(name);
	this->setMaxHitPoints(100);
	this->setHitPoints(100);
	this->setMaxEnergyPoints(100);
	this->setEnergyPoints(100);
	this->setLevel(1);
	this->setMeleeAttackDmg(30);
	this->setRangedAttackDmg(20);
	this->setArmorDmgReduction(5);
	this->_log();
	std::cout << "Start bootup sequence(param)." << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	*this = src;
	this->_log();
	std::cout << "Start bootup sequence(copy)." << std::endl;
	return;
}

FragTrap::~FragTrap(void) {
	this->_log();
	std::cout << "Robot down..." << std::endl;
	return;
}

FragTrap		&FragTrap::operator=(FragTrap const &rhs) {
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

void			FragTrap::vaulthunterDotExe(std::string const & target) {
	int	randIndex = 0;

	this->_log();
	if (this->getEnergyPoints() >= FragTrap::_specialAttackCost) {
		this->setEnergyPoints(this->getEnergyPoints() - FragTrap::_specialAttackCost);
		while (FragTrap::_specialAttacks[randIndex] != "")
			randIndex++;
		randIndex = rand() % randIndex;
		std::cout << "Push this button, flip this dongle, voila ! - Special attack " <<
		FragTrap::_specialAttacks[randIndex] << " on " << target << ", dealing " <<
		FragTrap::_specialAttackDmg << " points of damage !" << std::endl;
	}
	else
		std::cout << "I'm running out of energy -_-'" << std::endl;
}

void			FragTrap::_log(void) const {
	std::cout << "FR4G-TP (" << this->getName() << ") - ";	
}

unsigned int const	FragTrap::_specialAttackDmg = 35;
unsigned int const	FragTrap::_specialAttackCost = 25;
std::string const	FragTrap::_specialAttacks[] = { "Hyperion Punch", "Sniper Shot", "Laser Inferno", "Clap-in-the-Box", "Miniontrap" };