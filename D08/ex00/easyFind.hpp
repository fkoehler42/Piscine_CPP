/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:47:34 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 16:05:57 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T>
void	easyFind(T const &container, int toFind) {
	typename T::const_iterator found = std::find(container.begin(), container.end(), toFind);

	try {
		if (found == container.end())
			throw std::runtime_error("occurence not found.");
		std::cout << "easyFind : occurence found." << std::endl;
	} catch (std::exception const &ex) {  
		std::cout << "easyFind : " << ex.what() << std::endl;
	}
}

#endif