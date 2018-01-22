/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:20:01 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/17 14:01:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

//// Constructors / Destructor ////

Scalar::Scalar(void) : _val(NULL) {}

Scalar::Scalar(char *const val) : _val(val) {}

Scalar::Scalar(Scalar const &src) { *this = src; }

Scalar::~Scalar(void) {}

//// Accessors ////

char	*Scalar::getVal(void) const { return this->_val; }

//// Class Specific ////


//// Casts Operators ////

Scalar::operator char(void) const {
	char	ret;
	int		tmp;

	tmp = atoi(this->getVal());
	if (tmp < CHAR_MIN || tmp > CHAR_MAX)
		throw Scalar::ImpossibleCastException();
	else {
		ret = static_cast<char>(tmp);
		if (!isprint(ret))
			throw Scalar::NonDisplayableException();
		else
			return (ret);
	}
}

Scalar::operator int(void) const {
	int		ret;
	long	tmp;

	tmp = atol(this->getVal());
	if (tmp < INT_MIN || tmp > INT_MAX)
		throw Scalar::ImpossibleCastException();
	else {
		ret = static_cast<int>(tmp);
		return (ret);
	}
}

Scalar::operator float(void) const {
	float		ret;
	double		tmp;

	tmp = atof(this->getVal());
	if (tmp < INT_MIN || tmp > INT_MAX)
		throw Scalar::ImpossibleCastException();
	else {
		ret = static_cast<int>(tmp);
		return (ret);
	}
}

//// Operators Overloads ////

Scalar		&Scalar::operator=(Scalar const &rhs) {
	this->_val = rhs.getVal();
	return (*this);
}

//// Exceptions ////

Scalar::ImpossibleCastException::ImpossibleCastException(void) throw() { return; }
Scalar::ImpossibleCastException::ImpossibleCastException(ImpossibleCastException const &src) throw() { *this = src; }
Scalar::ImpossibleCastException::~ImpossibleCastException(void) throw() { return; }
Scalar::ImpossibleCastException	&Scalar::ImpossibleCastException::operator=(ImpossibleCastException const &rhs) {
	static_cast<void>(rhs);
	return (*this);
}
const char	*Scalar::ImpossibleCastException::what(void) const throw() { return ("Impossible"); }

Scalar::NonDisplayableException::NonDisplayableException(void) throw() { return; }
Scalar::NonDisplayableException::NonDisplayableException(NonDisplayableException const &src) throw() { *this = src; }
Scalar::NonDisplayableException::~NonDisplayableException(void) throw() { return; }
Scalar::NonDisplayableException	&Scalar::NonDisplayableException::operator=(NonDisplayableException const &rhs) {
	static_cast<void>(rhs);
	return (*this);
}
const char	*Scalar::NonDisplayableException::what(void) const throw() { return ("Non Displayable"); }