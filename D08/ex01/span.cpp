/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:31:05 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/19 19:19:15 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <numeric>
#include <climits>
#include "span.hpp"

//// Constructors / Destructor ////

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(Span const &src) : _maxSize(src.getMaxSize()) { *this = src; }

Span::~Span(void) {}

//// Accessors ////

unsigned int			Span::getMaxSize(void) const { return this->_maxSize; }
std::vector<int>		Span::getArray(void) const { return this->_array; }

//// Class Specific ////

void				Span::addNumber(int const n) {
	if (this->_array.size() >= this->getMaxSize())
		throw std::overflow_error("No space left to store new value.");
	else
		this->_array.push_back(n);
}

unsigned int		Span::shortestSpan(void) const {
	std::vector<int>			array = this->getArray();
	std::vector<int>::iterator	min_span;

	if (array.size() < 2)
		throw std::length_error("Not enough elements to compute a span");
	else {
		std::sort(array.begin(), array.end());
		std::adjacent_difference(array.begin(), array.end(), array.begin() - 1);
		min_span = std::min_element(array.begin(), array.end() - 1);
		return (static_cast<unsigned int>(*min_span));
	}
}

unsigned int		Span::longestSpan(void) const {
	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;
	std::vector<int>			array = this->getArray();

	if (array.size() < 2)
		throw std::length_error("Not enough elements to compute a span");
	else {
		min = std::min_element(array.begin(), array.end());
		max = std::max_element(array.begin(), array.end());
		return (static_cast<unsigned int>(abs(static_cast<long>(*max) - static_cast<long>(*min))));
	}
}

//// Operators Overloads ////

Span		&Span::operator=(Span const &rhs) {
	this->_array = rhs.getArray();
	return (*this);
}