/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:54:05 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:18:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) : _nb_zombies(0) {
	if (n > 0)
	{
		this->_nb_zombies = n;
		std::cout << "--- Generating a zombie horde ---" << std::endl;
		this->_setHorde(n);
	}
	else
		std::cout << "Invalid number of zombies" << std::endl;
}

ZombieHorde::~ZombieHorde(void) {
	std::cout << "--- Destroying a zombie horde ---" << std::endl;
	delete [] _getHorde();
	return;
}

Zombie	*ZombieHorde::_getHorde(void) const{ return (this->_horde); }

void	ZombieHorde::_setHorde(int n) {
	this->_horde = new Zombie[n];
}

void	ZombieHorde::announce(void) const {
	for (int i = 0; i < this->_nb_zombies; i++)
		this->_horde[i].announce();
}