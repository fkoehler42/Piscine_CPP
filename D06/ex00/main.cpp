/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:17:14 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/17 14:09:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Scalar.hpp"

int	main(int ac, char **av) {
	Scalar				scalar(av[1]);

	if (ac != 2)
		return (0);
	try { std::cout << "char : '" << scalar.operator char() << '\'' << std::endl; }
	catch (std::exception const &ex) { std::cout << "char : " << ex.what() << std::endl;	}
	try { std::cout << "int : " << static_cast<int>(scalar) << std::endl; }
	catch (std::exception const &ex) { std::cout << "int : " << ex.what() << std::endl;	}
	return (0);
}