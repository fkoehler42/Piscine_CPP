/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:41:18 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 09:55:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Pony.hpp"

void	ponyOnTheHeap(void) {
	Pony	*mlp = new Pony(18);

	mlp->saveTheWorld();
	delete mlp;
	return;
}

void	ponyOnTheStack(void) {
	Pony	mlp(42);

	mlp.saveTheWorld();
	return;
}

int		main(void) {

	std::cout << "Summon a pony on the heap" << std::endl; 
	ponyOnTheHeap();
	std::cout << std::endl << "Summon a pony on the stack" << std::endl; 
	ponyOnTheStack();
	return (0);
}