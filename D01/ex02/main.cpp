/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:40:57 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 11:53:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieEvent.hpp"

#define NB_ZOMBIES 5

int	main(void) {
	ZombieEvent	zombiesHandler;

	for (size_t i = 0; i < NB_ZOMBIES; i++)
		zombiesHandler.randomChump();
	return (0);
}