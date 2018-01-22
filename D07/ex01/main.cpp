/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:39:19 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/17 18:09:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include "FixedClass.hpp"

int main( void ) {
	int		*val = new int[4];
	Fixed	*fixed = new Fixed[3];

	std::cout << "int array init" << std::endl;
	iter(&val, 4, init);
	iter(&val, 4, print);

	std::cout << "int array random multiply" << std::endl;
	iter(&val, 4, randomMultiply);
	iter(&val, 4, print);

	std::cout << "fixed class init value : " << fixed[0] << std::endl;
	std::cout << "fixed class increment" << std::endl;
	iter(&fixed, 3, increment);
	iter(&fixed, 3, print);

	delete [] val;
	delete [] fixed;

	return 0;
}