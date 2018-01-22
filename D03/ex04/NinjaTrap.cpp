/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:15:38 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 12:56:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {
	this->_log();
	std::cout << "Here I am, hidden in the shadow(default)." << std::endl;
	return;
}

NinjaTrap::NinjaTrap(std::string const name) {
	this->setName(name);
	this->setMaxHitPoints(60);
	this->setHitPoints(60);
	this->setMaxEnergyPoints(120);
	this->setEnergyPoints(120);
	this->setLevel(1);
	this->setMeleeAttackDmg(60);
	this->setRangedAttackDmg(5);
	this->setArmorDmgReduction(0);
	this->_log();
	std::cout << "Here I am, hidden in the shadow(param)." << std::endl;
	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
	*this = src;
	this->_log();
	std::cout << "Here I am, hidden in the shadow(copy)." << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void) {
	this->_log();
	std::cout << "I have many regrets !" << std::endl;
	return;
}

NinjaTrap		&NinjaTrap::operator=(NinjaTrap const &rhs) {
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

void			NinjaTrap::ninjaShoeBox(NinjaTrap const &target) const {
	this->_log();
	std::cout << "Listen " << target.getName() << ". " <<
	"01010110 01001001 01010110 01000001 00100000 01001100 01000001 00100000 01010010 01001111 01010010 01001111 01001100 01010101 01010100 01001001 01001111 01001110" << std::endl;
}

void			NinjaTrap::ninjaShoeBox(FragTrap const &target) const {
	this->_log();
	std::cout << "Wow " << target.getName() << " ! You're the alpha version of ClapTrap" << std::endl;
}

void			NinjaTrap::ninjaShoeBox(ScavTrap const &target) const {
	this->_log();
	std::cout << "Hey " << target.getName() << " ! Viva La Robolution !" << std::endl;
}

void			NinjaTrap::ninjaShoeBox(ClapTrap const &target) const {
	this->_log();
	std::cout << target.getName() << " ! I love you mummy <3" << std::endl;
}

void			NinjaTrap::_log(void) const {
	std::cout << "NINJ4-TP (" << this->getName() << ") - ";	
}