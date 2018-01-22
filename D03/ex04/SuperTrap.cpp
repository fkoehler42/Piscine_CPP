/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 12:56:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) {
	this->_log();
	std::cout << "Here I am, hidden in the shadow(default)." << std::endl;
	return;
}

SuperTrap::SuperTrap(std::string const name) {
	this->setName(name);
	this->setMaxHitPoints(100);
	this->setHitPoints(100);
	this->setMaxEnergyPoints(120);
	this->setEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDmg(60);
	this->setRangedAttackDmg(20);
	this->setArmorDmgReduction(5);
	this->_log();
	std::cout << "Here I am, hidden in the shadow(param)." << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const &src) {
	*this = src;
	this->_log();
	std::cout << "Here I am, hidden in the shadow(copy)." << std::endl;
	return;
}

SuperTrap::~SuperTrap(void) {
	this->_log();
	std::cout << "I have many regrets !" << std::endl;
	return;
}

SuperTrap		&SuperTrap::operator=(SuperTrap const &rhs) {
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

void			SuperTrap::meleeAttack(std::string const &target) { this->FragTrap::meleeAttack(target); }
void			SuperTrap::rangedAttack(std::string const &target) { this->NinjaTrap::rangedAttack(target); }

void			SuperTrap::_log(void) const {
	std::cout << "SUP3R-TP (" << this->getName() << ") - ";	
}