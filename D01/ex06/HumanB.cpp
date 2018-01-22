/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 21:51:57 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 22:07:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) { return; }

HumanB::~HumanB(void) { return; }

const std::string	HumanB::getName(void) const { return (this->name); }

const Weapon		*HumanB::getWeapon(void) const { return (this->weapon); }

void				HumanB::attack(void) const {
	std::cout << this->getName() << " attacks with his " <<
	this->getWeapon()->getType() << std::endl;
}

void				HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	return;
}