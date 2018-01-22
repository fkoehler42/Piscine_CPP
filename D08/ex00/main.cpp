/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:46:55 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 16:19:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include "easyFind.hpp"

void	display(int i) { std::cout << i << ' '; }

int		main(void) {
	std::list<int>		intList;
	std::vector<int>	intVector;
	
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
		intList.push_back(rand() % 10);

	for (size_t i = 0; i < 10; i++)
		intVector.push_back(rand() % 10);
	
	std::cout << "intList contains the following values :" << std::endl;
	std::for_each(intList.begin(), intList.end(), display);
	std::cout << std::endl << "easyFind(intList, 5) : " << std::endl;
	easyFind(intList, 5);

	std::cout << std::endl << "intVector contains the following values :" << std::endl;
	std::for_each(intVector.begin(), intVector.end(), display);
	std::cout << std::endl << "easyFind(intVector, 5) : " << std::endl;
	easyFind(intVector, 5);

	return (0);
}