/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:33:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 14:44:48 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	Judith("Judith");
	FragTrap	Jack("Jack");
	ScavTrap	John("John");

	std::cout << std::endl << "FragTrap actions :" << std::endl;
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

	std::cout << std::endl <<"ScavTrap actions :" << std::endl;
	John.meleeAttack("Enemy");
	John.rangedAttack("Enemy");
	John.takeDamage(5);
	John.takeDamage(15);
	John.beRepaired(10);
	John.challengeNewComer("Jack");
	John.challengeNewComer("Judith");
	John.challengeNewComer("Jack");
	John.challengeNewComer("Judith");

	std::cout << std::endl <<"ClapTrap actions :" << std::endl;
	Judith.meleeAttack("Enemy");
	Judith.rangedAttack("Enemy");
	Judith.takeDamage(5);
	Judith.takeDamage(15);
	Judith.beRepaired(10);
	std::cout << std::endl;

	return (0);
}