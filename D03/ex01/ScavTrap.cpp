/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 12:34:12 by fkoehler         ###   ########.fr       */
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

ScavTrap::ScavTrap(std::string const name) : _hitPoints(100), _maxHitPoints(100),
_energyPoints(50), _maxEnergyPoints(50), _level(1), _meleeAttackDmg(20),
_rangedAttackDmg(15), _armorDmgReduction(3), _name(name) {
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
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

unsigned int	ScavTrap::getHitPoints(void) const { return (this->_hitPoints); }
unsigned int	ScavTrap::getMaxHitPoints(void) const { return (this->_maxHitPoints); }
unsigned int	ScavTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
unsigned int	ScavTrap::getMaxEnergyPoints(void) const { return (this->_maxEnergyPoints); }
unsigned int	ScavTrap::getLevel(void) const { return (this->_level); }
unsigned int	ScavTrap::getMeleeAttackDmg(void) const { return (this->_meleeAttackDmg); }
unsigned int	ScavTrap::getRangedAttackDmg(void) const { return (this->_rangedAttackDmg); }
unsigned int	ScavTrap::getArmorDmgReduction(void) const { return (this->_armorDmgReduction); }
std::string		ScavTrap::getName(void) const { return (this->_name); }

void			ScavTrap::setHitPoints(unsigned int n) {
	if (n > this->getMaxHitPoints())
		n = this->getMaxHitPoints();
	this->_hitPoints = n;
}

void			ScavTrap::setMaxHitPoints(unsigned int n) { this->_maxHitPoints = n; }

void			ScavTrap::setEnergyPoints(unsigned int n) {
	if (n > this->getMaxEnergyPoints())
		n = this->getMaxEnergyPoints();
	this->_energyPoints = n;
}

void			ScavTrap::setMaxEnergyPoints(unsigned int n) { this->_maxEnergyPoints = n; }
void			ScavTrap::setLevel(unsigned int n) { this->_level = n; }
void			ScavTrap::setMeleeAttackDmg(unsigned int n) { this->_meleeAttackDmg = n; }
void			ScavTrap::setRangedAttackDmg(unsigned int n) { this->_rangedAttackDmg = n; }
void			ScavTrap::setArmorDmgReduction(unsigned int n) { this->_armorDmgReduction = n; }
void			ScavTrap::setName(std::string name) { this->_name = name; }


void			ScavTrap::meleeAttack(std::string const &target) {
	this->_log();
	std::cout << "Meet professor punch ! - Melee attack on " << target
	<< ", dealing " << this->getMeleeAttackDmg() << " points of damage !" << std::endl;
	return;
}

void			ScavTrap::rangedAttack(std::string const &target) {
	this->_log();
	std::cout << "Crack shot ! - Ranged attack on "	<< target << ", dealing "
	<< this->getRangedAttackDmg() << " points of damage !" << std::endl;
	return;
}

void			ScavTrap::takeDamage(unsigned int amount) {
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
		std::cout << "Why do I even feel pain ?! - Takes " << realDmg
		<< " points of damage." << std::endl;
	}
	else
		std::cout << "You can't keep a good 'bot down ! - Doesn't take any damage." << std::endl;
	return;
}

void			ScavTrap::beRepaired(unsigned int amount) {
	unsigned int	realHeal;

	this->_log();
	if (this->getHitPoints() + amount > this->getMaxHitPoints())
		realHeal = this->getMaxHitPoints() - this->getHitPoints();
	else
		realHeal = amount;
	this->setHitPoints(this->getHitPoints() + realHeal);
	std::cout << "Make my day. - Recovering " << realHeal << " life points." << std::endl;
	return;
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
