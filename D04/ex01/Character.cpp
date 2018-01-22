/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:07:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 22:17:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

#define MAX_AP 40
#define RECOV_AP 10

Character::Character(void) { return; }

Character::Character(std::string const &name) : _name(name), _ap(MAX_AP), _weapon(nullptr) { return; }

Character::Character(Character const &src) { *this = src; }

Character::~Character(void) { return; }

Character		&Character::operator=(Character const &rhs) {
	this->setName(rhs.getName());
	this->setAP(rhs.getAP());
	this->equip(rhs.getWeapon());
	return (*this);
}

std::string		Character::getName(void) const { return this->_name; }
int				Character::getAP(void) const { return this->_ap; }

AWeapon			*Character::getWeapon(void) const { return this->_weapon; }

std::string		Character::getStats(void) const {
	std::string	stats;

	if (this->getWeapon() != nullptr)
		stats = this->getName() + " has " + std::to_string(this->getAP()) + " AP and wields a " + this->getWeapon()->getName() + '\n';
	else
		stats = this->getName() + " has " + std::to_string(this->getAP()) + " AP and is unarmed\n";
	return (stats);
}

void			Character::setName(std::string name) { this->_name = name; }
void			Character::setAP(int ap) { this->_ap = ap; }

void			Character::recoverAP(void) {
	if (this->getAP() < MAX_AP) {
		if (this->getAP() + RECOV_AP < MAX_AP)
			this->setAP(this->getAP() + RECOV_AP);
		else
			this->setAP(MAX_AP);
	}
}

void			Character::equip(AWeapon *weapon) { this->_weapon = weapon; }

void			Character::attack(Enemy *enemy) {
	if (this->getAP() < this->getWeapon()->getAPCost())
		return;
	this->setAP(this->getAP() - this->getWeapon()->getAPCost());
	std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << '\n';
	this->getWeapon()->attack();
	enemy->takeDamage(this->getWeapon()->getDamage());
}

std::ostream	&operator<<(std::ostream &os, Character const &rhs) {
	os << rhs.getStats();
	return (os);
}