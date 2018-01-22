/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:50:47 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:32:03 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/time.h>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) { return; }

ZombieEvent::~ZombieEvent(void) { return; }

void	ZombieEvent::setZombieType(Zombie *zombie) {
	int	i = 0;
	int	randIndex;

	while (Zombie::types[i] != "")
		i++;
	randIndex = rand() % i;
	zombie->setType(Zombie::types[randIndex]);
}

Zombie	*ZombieEvent::newZombie(std::string name) {
	Zombie	*zombie = new Zombie;

	zombie->setName(name);
	this->setZombieType(zombie);
	return (zombie);
}

void	ZombieEvent::randomChump() {
	int		i = 0;
	int		randIndex;
	Zombie	*zombie;
	struct timeval	timeVal;

	gettimeofday(&timeVal, NULL);
	srand(timeVal.tv_usec * timeVal.tv_sec);
	while (Zombie::names[i] != "")
		i++;
	randIndex = rand() % i;
	zombie = this->newZombie(Zombie::names[randIndex]);
	this->setZombieType(zombie);
	zombie->announce();
	delete zombie;
	return;
}