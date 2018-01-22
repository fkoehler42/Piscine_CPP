/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:33:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 15:45:20 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int	main(void) {
	ClapTrap	Judith("Judith");
	FragTrap	Jack("Jack");
	ScavTrap	John("John");
	NinjaTrap	Jarod("Jarod");
	SuperTrap	Joshua("Joshua");

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

	std::cout << std::endl <<"NinjaTrap actions :" << std::endl;
	Jarod.meleeAttack("Enemy");
	Jarod.rangedAttack("Enemy");
	Jarod.takeDamage(5);
	Jarod.takeDamage(15);
	Jarod.beRepaired(10);
	Jarod.ninjaShoeBox(Judith);
	Jarod.ninjaShoeBox(Jack);
	Jarod.ninjaShoeBox(John);
	Jarod.ninjaShoeBox(Jarod);

	std::cout << std::endl <<"NinjaTrap actions :" << std::endl;
	std::cout << Joshua.getHitPoints() << std::endl;
	Joshua.meleeAttack("everyone");
	Joshua.vaulthunterDotExe("everyone");
	Joshua.ninjaShoeBox(Jarod);

	std::cout << std::endl;
	return (0);
}