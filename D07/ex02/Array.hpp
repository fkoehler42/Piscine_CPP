/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:33:09 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 14:08:07 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {

	public:

		Array<T>(void) : _size(0), _array(new T[0]()) {}
		Array<T>(unsigned int const n) : _size(n), _array(new T[n]()) {}
		Array<T>(Array const &src) { *this = src; }
		~Array<T>(void) { delete [] this->_array; }

		T			&operator[](unsigned int i) {
			if (i >= this->_size)
				throw std::out_of_range("Element is out of the limits.");
			else
				return (this->_array[i]);
		}

		Array<T>	&operator=(Array<T> const &rhs) {
			delete [] this->_array;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = rhs._array[i];
			return (*this);
		}

		unsigned int		size(void) const { return this->_size; }

	private:

		unsigned int	_size;
		T				*_array;
};

#endif