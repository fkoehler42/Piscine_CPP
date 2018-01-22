/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 12:57:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/time.h>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_log();
	std::cout << "Parent class constructor(default)." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const name) : _hitPoints(150), _maxHitPoints(150),
_energyPoints(150), _maxEnergyPoints(150), _level(1), _meleeAttackDmg(50),
_rangedAttackDmg(40), _armorDmgReduction(10), _name(name) {
	this->_log();
	std::cout << "Parent class constructor(param)." << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	this->_log();
	std::cout << "Parent class constructor(copy)." << std::endl;
	return;
}

ClapTrap::~ClapTrap(void) {
	this->_log();
	std::cout << "Parent class destructor" << std::endl;
	return;
}

ClapTrap		&ClapTrap::operator=(ClapTrap const &rhs) {
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

unsigned int	ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }
unsigned int	ClapTrap::getMaxHitPoints(void) const { return (this->_maxHitPoints); }
unsigned int	ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
unsigned int	ClapTrap::getMaxEnergyPoints(void) const { return (this->_maxEnergyPoints); }
unsigned int	ClapTrap::getLevel(void) const { return (this->_level); }
unsigned int	ClapTrap::getMeleeAttackDmg(void) const { return (this->_meleeAttackDmg); }
unsigned int	ClapTrap::getRangedAttackDmg(void) const { return (this->_rangedAttackDmg); }
unsigned int	ClapTrap::getArmorDmgReduction(void) const { return (this->_armorDmgReduction); }
std::string		ClapTrap::getName(void) const { return (this->_name); }

void			ClapTrap::setHitPoints(unsigned int n) {
	if (n > this->getMaxHitPoints())
		n = this->getMaxHitPoints();
	this->_hitPoints = n;
}

void			ClapTrap::setMaxHitPoints(unsigned int n) { this->_maxHitPoints = n; }
void			ClapTrap::setEnergyPoints(unsigned int n) {
	if (n > this->getMaxEnergyPoints())
		n = this->getMaxEnergyPoints();
	this->_energyPoints = n;
}
void			ClapTrap::setMaxEnergyPoints(unsigned int n) { this->_maxEnergyPoints = n; }
void			ClapTrap::setLevel(unsigned int n) { this->_level = n; }
void			ClapTrap::setMeleeAttackDmg(unsigned int n) { this->_meleeAttackDmg = n; }
void			ClapTrap::setRangedAttackDmg(unsigned int n) { this->_rangedAttackDmg = n; }
void			ClapTrap::setArmorDmgReduction(unsigned int n) { this->_armorDmgReduction = n; }
void			ClapTrap::setName(std::string name) { this->_name = name; }


void			ClapTrap::meleeAttack(std::string const &target) {
	this->_log();
	std::cout << "Ready for the PUNCHline ?! - Melee attack on " << target
	<< ", dealing " << this->getMeleeAttackDmg() << " points of damage !" << std::endl;
	return;
}

void			ClapTrap::rangedAttack(std::string const &target) {
	this->_log();
	std::cout << "Take two bullets, then call me in the morning ! - Ranged attack on "
	<< target << ", dealing " << this->getRangedAttackDmg() << " points of damage !" << std::endl;
	return;
}

void			ClapTrap::takeDamage(unsigned int amount) {
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

void			ClapTrap::beRepaired(unsigned int amount) {
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

void			ClapTrap::_log(void) const {
	std::cout << "CL4P-TP (" << this->getName() << ") - ";	
}