/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 16:33:46 by fkoehler         ###   ########.fr       */
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

FragTrap::FragTrap(std::string const name) : _hitPoints(100), _maxHitPoints(100),
_energyPoints(100), _maxEnergyPoints(100), _level(1), _meleeAttackDmg(30),
_rangedAttackDmg(20), _armorDmgReduction(5), _name(name) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);	this->_log();
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

unsigned int	FragTrap::getHitPoints(void) const { return (this->_hitPoints); }
unsigned int	FragTrap::getMaxHitPoints(void) const { return (this->_maxHitPoints); }
unsigned int	FragTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
unsigned int	FragTrap::getMaxEnergyPoints(void) const { return (this->_maxEnergyPoints); }
unsigned int	FragTrap::getLevel(void) const { return (this->_level); }
unsigned int	FragTrap::getMeleeAttackDmg(void) const { return (this->_meleeAttackDmg); }
unsigned int	FragTrap::getRangedAttackDmg(void) const { return (this->_rangedAttackDmg); }
unsigned int	FragTrap::getArmorDmgReduction(void) const { return (this->_armorDmgReduction); }
std::string		FragTrap::getName(void) const { return (this->_name); }

void			FragTrap::setHitPoints(unsigned int n) {
	if (n > this->getMaxHitPoints())
		n = this->getMaxHitPoints();
	this->_hitPoints = n;
}

void			FragTrap::setMaxHitPoints(unsigned int n) { this->_maxHitPoints = n; }

void			FragTrap::setEnergyPoints(unsigned int n) {
	if (n > this->getMaxEnergyPoints())
		n = this->getMaxEnergyPoints();
	this->_energyPoints = n;
}

void			FragTrap::setMaxEnergyPoints(unsigned int n) { this->_maxEnergyPoints = n; }
void			FragTrap::setLevel(unsigned int n) { this->_level = n; }
void			FragTrap::setMeleeAttackDmg(unsigned int n) { this->_meleeAttackDmg = n; }
void			FragTrap::setRangedAttackDmg(unsigned int n) { this->_rangedAttackDmg = n; }
void			FragTrap::setArmorDmgReduction(unsigned int n) { this->_armorDmgReduction = n; }
void			FragTrap::setName(std::string name) { this->_name = name; }


void			FragTrap::meleeAttack(std::string const &target) {
	this->_log();
	std::cout << "Ready for the PUNCHline ?! - Melee attack on " << target
	<< ", dealing " << this->getMeleeAttackDmg() << " points of damage !" << std::endl;
	return;
}

void			FragTrap::rangedAttack(std::string const &target) {
	this->_log();
	std::cout << "Take two bullets, then call me in the morning ! - Ranged attack on "
	<< target << ", dealing " << this->getRangedAttackDmg() << " points of damage !" << std::endl;
	return;
}

void			FragTrap::takeDamage(unsigned int amount) {
	unsigned int	realDmg;

	this->_log();
	if (this->getArmorDmgReduction() < amount) {
		realDmg = amount - this->getArmorDmgReduction();
		if (this->getHitPoints() > realDmg)
			this->setHitPoints(this->getHitPoints() - realDmg);
		else {
			realDmg = this->getHitPoints();
			this->setHitPoints(0);
		}
		std::cout << "Ow hohoho, that hurts ! - Takes " << realDmg
		<< " points of damage." << std::endl;
	}
	else
		std::cout << "Hahahahaha! I'm alive ! - Doesn't take any damage." << std::endl;
	return;
}

void			FragTrap::beRepaired(unsigned int amount) {
	unsigned int	realHeal;

	this->_log();
	if (this->getHitPoints() + amount > this->getMaxHitPoints())
		realHeal = this->getMaxHitPoints() - this->getHitPoints();
	else
		realHeal = amount;
	this->setHitPoints(this->getHitPoints() + realHeal);
	std::cout << "Hit me, baby ! - Recovering " << realHeal << " life points." << std::endl;
	return;
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