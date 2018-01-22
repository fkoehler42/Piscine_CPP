/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:31:44 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 19:46:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(void) { return; }

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name),
_apcost(apcost), _damage(damage) { return; }

AWeapon::AWeapon(AWeapon const &src) { *this = src; }

AWeapon::~AWeapon(void) { return; }

AWeapon		&AWeapon::operator=(AWeapon const &rhs) {
	this->setName(rhs.getName());
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return (*this);
}

std::string		AWeapon::getName(void) const { return (this->_name); }
int				AWeapon::getAPCost(void) const { return (this->_apcost); }
int				AWeapon::getDamage(void) const { return (this->_damage); }

void			AWeapon::setName(std::string name) { this->_name = name; }
void			AWeapon::setAPCost(int apcost) { this->_apcost = apcost; }
void			AWeapon::setDamage(int damage) {this->_damage = damage; }