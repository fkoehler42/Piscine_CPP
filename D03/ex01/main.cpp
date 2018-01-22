/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:33:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 13:02:26 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	FragTrap	Jack("Jack");
	ScavTrap	Jones("Jones");

	std::cout << std::endl;

	Jack.meleeAttack("Enemy");
	Jack.rangedAttack("Enemy");
	Jack.takeDamage(5);
	Jack.takeDamage(150);
	Jack.beRepaired(25);
	Jack.beRepaired(125);
	Jack.beRepaired(25);
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");

	std::cout << std::endl;

	Jones.meleeAttack("Enemy");
	Jones.rangedAttack("Enemy");
	Jones.takeDamage(15);
	Jones.beRepaired(10);
	Jones.challengeNewComer("Jack");
	Jones.challengeNewComer("Jack");
	Jones.challengeNewComer("Jack");
	Jones.challengeNewComer("Jack");

	return (0);
}
