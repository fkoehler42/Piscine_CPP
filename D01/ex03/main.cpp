/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:13:32 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:23:20 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ZombieHorde.hpp"

int	main(void) {
	ZombieHorde	*horde1 = new ZombieHorde(5);
	ZombieHorde	horde2(3);

	std::cout <<  std::endl << "[heap] Horde announcement" << std::endl;
	horde1->announce();
	std::cout <<  std::endl << "[heap] delete on horde" << std::endl;
	delete horde1;
	std::cout <<  std::endl << "[stack] Horde announcement" << std::endl;
	horde2.announce();
	std::cout <<  std::endl << "End of function" << std::endl;
	return (0);
}