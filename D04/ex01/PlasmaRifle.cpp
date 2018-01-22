/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:46:41 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 20:05:08 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) { return; }

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src.getName(), src.getAPCost(), src.getDamage()) { *this = src; }

PlasmaRifle::~PlasmaRifle(void) { return; }

void			PlasmaRifle::attack(void) const {
	std::cout << "* piouuu piouuu piouuu *" <<std::endl;
	return;
}