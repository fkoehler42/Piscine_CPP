/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:13:24 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 19:12:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "New brain created" << std::endl;
	return;
}

Brain::~Brain(void) {
	std::cout << "Brain deleted" << std::endl;
	return;
}

std::string	Brain::identify(void) const {
	std::stringstream	ss;
	
	ss << this;
	return (ss.str());
}