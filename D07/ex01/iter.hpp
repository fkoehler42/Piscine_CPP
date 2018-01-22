/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:07:07 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 11:03:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array[], int const len, void(*func)(T&)) {
	for (int i = 0; i < len; i++)
		func((*array)[i]);
}

template<typename T>
void	iter(T *array[], size_t const len, void(*func)(T&)) {
	for (size_t i = 0; i < len; i++)
		func((*array)[i]);
}

template<typename T>
void	randomMultiply(T &x) { x *= rand() % 100; }

template<typename T>
void	init(T &x) { x = 1; }

template<typename T>
void	increment(T &x) { x++; }

template<typename T>
void	print(T &x) { std::cout << x << std::endl; }

#endif