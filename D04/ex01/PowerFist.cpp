/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:46:41 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 19:57:58 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) { return; }

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src.getName(), src.getAPCost(), src.getDamage()) { *this = src; }

PowerFist::~PowerFist(void) { return; }

void			PowerFist::attack(void) const {
	std::cout << "* pschhh... SBAM! *" <<std::endl;
	return;
}