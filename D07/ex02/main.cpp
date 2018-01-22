/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:15:41 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 14:12:36 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "FixedClass.hpp"

int		main(void) {
	Array<int>		intArray(4);
	Array<Fixed>	fixedArray(15);
	Array<Fixed>	emptyArray;

	try {
		intArray[0] = 42;
		std::cout << "after assignation, intArray[0] = " << intArray[0] << std::endl;

		std::cout << "fixedArray[5] = " << fixedArray[5] << std::endl;
		fixedArray[5]++;
		std::cout << "after increment, fixedArray[5] = " << fixedArray[5] << std::endl;

		emptyArray = fixedArray;
		std::cout << "emptyArray instanciated by default constructor then assignated to fixedArray value, emptyArray[5] = " << emptyArray[5] << std::endl;

		std::cout << "Trying to access an out of range element inside fixedArray -> " << fixedArray[15] << std::endl;
	}
	catch (std::exception const &ex) { std::cout << "Error : " << ex.what() << std::endl; }

	return (0);
}