/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:03:28 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 22:00:24 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name),
weapon(weapon) { return; }

HumanA::~HumanA(void) { return; }

const std::string	HumanA::getName(void) const { return (this->name); }

const Weapon		&HumanA::getWeapon(void) const { return (this->weapon); }

void				HumanA::attack(void) const {
	std::cout << this->getName() << " attacks with his " <<
	this->getWeapon().getType() << std::endl;
}


