/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:51:44 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 09:54:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

Pony::Pony(int power) : _magicalPower(power) {
	std::cout << "A pony is born !!" << std::endl;
}

Pony::~Pony(void) {
	std::cout << "A pony is dead -_-'" << std::endl;
}

int		Pony::getMagicalPower(void) const { return (this->_magicalPower); }

void	Pony::saveTheWorld(void) const {
	if (this->getMagicalPower() != 42)
		std::cout << "I'm not strong enough to save you all fools ! " << std::endl;
	else
		std::cout << "Take some perlimpinpin's powder and let's save the world !" << std::endl;
}