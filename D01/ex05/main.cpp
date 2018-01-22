/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:05:56 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 19:31:49 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

void heap_version() {
	Human	*boby = new Human();
	Human	&bob = *boby;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	std::cout << "CALL DELETE ON ALLOCATED HUMAN" << std::endl;
	delete boby;
	std::cout << "RETURN TO MAIN" << std::endl << std::endl;
}

int main() {
	Human bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;

	std::cout << std::endl << "CALL HEAP FUNCTION" << std::endl;
	heap_version();
	std::cout << "AFTER HEAP FUNCTION" << std::endl;
}
