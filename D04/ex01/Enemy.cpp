/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:33:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 22:15:04 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(void) { return; }

Enemy::Enemy(int hp, std::string const &type) : _type(type), _hp(hp) { return; }

Enemy::Enemy(Enemy const &src) { *this = src; }

Enemy::~Enemy(void) { return; }

Enemy		&Enemy::operator=(Enemy const &rhs) {
	this->setType(rhs.getType());
	this->setHP(rhs.getHP());
	return (*this);
}

int				Enemy::getHP(void) const { return this->_hp; }
std::string		Enemy::getType(void) const { return this->_type; }

void			Enemy::setHP(int hp) { this->_hp = hp; }
void			Enemy::setType(std::string const type) { this->_type = type; }

void			Enemy::takeDamage(int amount) {
	if (amount > 0) {
		if (this->getHP() <= amount)
			this->setHP(0);
		else
			this->setHP(this->getHP() - amount);
	}
	if (this->getHP() == 0)
		this->~Enemy();
}