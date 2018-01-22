/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:24:20 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 19:17:19 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void) {
	std::cout << "New Human created" << std::endl;
	return;
}

Human::~Human(void) {
	std::cout << "Human deleted" << std::endl;
	return;
}

Brain const	&Human::getBrain(void) const { return (this->_brain); }

std::string	Human::identify(void) const { return (this->getBrain().identify()); }