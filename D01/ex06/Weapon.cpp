/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:39:33 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 20:14:48 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->setType(type);
	return;
}

Weapon::~Weapon(void) { return; }

const std::string	&Weapon::getType(void) const{ return (this->type); }

void				Weapon::setType(std::string type) {
	this->type = type;
	return;
}
