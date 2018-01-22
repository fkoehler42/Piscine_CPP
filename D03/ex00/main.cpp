/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:33:43 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/11 17:45:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	FragTrap	Jack("Jack");
	FragTrap	JackCopy(Jack);

	Jack.meleeAttack("Enemy");
	Jack.rangedAttack("Enemy");
	Jack.takeDamage(150);
	Jack.beRepaired(25);
	Jack.beRepaired(125);
	Jack.beRepaired(25);
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");
	Jack.vaulthunterDotExe("Boss");

	return (0);
}