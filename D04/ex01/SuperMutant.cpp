/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:43:18 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 20:54:24 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src.getHP(), src.getType()) {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
	*this = src;
}

SuperMutant::~SuperMutant(void) { std::cout << "Aaargh ..." << std::endl; }

void	SuperMutant::takeDamage(int amount) { Enemy::takeDamage(amount - 3); }