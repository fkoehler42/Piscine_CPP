/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:01:19 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 19:47:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "FixedClass.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
	return;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(int const n) {
	std::cout << "Integer constructor called" << std::endl;
	this->setRawBits(n << _fractionalBits);
	return;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)(roundf(n * _powBits(_fractionalBits))));
	return;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed			&Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_rawValue = rhs.getRawBits();
	return (*this);
}

int				Fixed::getRawBits(void) const { return (this->_rawValue); }

void			Fixed::setRawBits(int const raw) { this->_rawValue = raw; }

int				Fixed::toInt(void) const { return (getRawBits() >> _fractionalBits); }

float			Fixed::toFloat(void) const { return (roundf(getRawBits()) / _powBits(_fractionalBits)); }

int				Fixed::_powBits(int const nBits) {
	int	ret = 2;

	for (int i = 0; i < nBits - 1; i++) {
		ret *= 2;
	}
	return (ret);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &rhs) {
	os << rhs.toFloat();
	return (os);
}

const int	Fixed::_fractionalBits = 8;