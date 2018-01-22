/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedClass.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:01:19 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/17 16:02:15 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "FixedClass.hpp"

Fixed::Fixed(void) { this->setRawBits(0); return; }

Fixed::Fixed(Fixed const &src) { *this = src; return; }

Fixed::Fixed(int const n) { this->setRawBits(n << _fractionalBits);	return; }

Fixed::Fixed(float const n) {
	this->setRawBits((int)(roundf(n * _powBits(_fractionalBits))));
	return;
}

Fixed::~Fixed(void) { return; }

Fixed			&Fixed::operator=(Fixed const &rhs) {
	this->_rawValue = rhs.getRawBits();
	return (*this);
}

bool			Fixed::operator<(Fixed const &rhs) const { return (this->toFloat() < rhs.toFloat()); }

bool			Fixed::operator>(Fixed const &rhs) const { return (this->toFloat() > rhs.toFloat()); }

bool			Fixed::operator<=(Fixed const &rhs) { return (this->toFloat() <= rhs.toFloat()); }

bool			Fixed::operator>=(Fixed const &rhs) { return (this->toFloat() >= rhs.toFloat()); }

bool			Fixed::operator==(Fixed const &rhs) { return (this->toFloat() == rhs.toFloat()); }

bool			Fixed::operator!=(Fixed const &rhs) { return (this->toFloat() != rhs.toFloat()); }

Fixed			Fixed::operator+(Fixed const &rhs) { return (Fixed(this->toFloat() + rhs.toFloat())); }

Fixed			Fixed::operator-(Fixed const &rhs) { return (Fixed(this->toFloat() - rhs.toFloat())); }

Fixed			Fixed::operator*(Fixed const &rhs) { return (Fixed(this->toFloat() * rhs.toFloat())); }

Fixed			Fixed::operator/(Fixed const &rhs) {
	if (rhs.toFloat() == 0) {
		std::cout << "Forbidden operation (divide by 0)" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / rhs.toFloat())); }

Fixed			&Fixed::operator++(void) { // pre-increment
	this->_rawValue++;
	return (*this);
}

Fixed			Fixed::operator++(int) { // post-increment
	Fixed	save = *this;

	++(*this);
	return (save);
}

Fixed			&Fixed::operator--(void) {
	this->_rawValue--;
	return (*this);
}

Fixed			Fixed::operator--(int) {
	Fixed	save = *this;

	--(*this);
	return (save);
}

int				Fixed::getRawBits(void) const { return (this->_rawValue); }

void			Fixed::setRawBits(int const raw) { this->_rawValue = raw; }

int				Fixed::toInt(void) const { return (getRawBits() >> _fractionalBits); }

float			Fixed::toFloat(void) const { return (roundf(getRawBits()) / _powBits(_fractionalBits)); }

Fixed			&Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed2 < fixed1)
		return (fixed2);
	return (fixed1);
}

Fixed const		&Fixed::min(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed2.toFloat() < fixed1.toFloat())
		return (fixed2);
	return (fixed1);
}

Fixed			&Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed2 > fixed1)
		return (fixed2);
	return (fixed1);
}

Fixed const		&Fixed::max(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed2.toFloat() > fixed1.toFloat())
		return (fixed2);
	return (fixed1);
}

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