/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateFunctions.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:41:56 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 11:04:21 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATEFUNCTIONS_HPP
#define TEMPLATEFUNCTIONS_HPP

template<typename T>
T const	&min(T const &x, T const &y) {
	return (x < y ? x : y);
}

template<typename T>
T const	&max(T const &x, T const &y) {
	return (x > y ? x : y);
}

template<typename T>
void	swap(T &x, T &y) {
	T	tmp = x;
	x = y;
	y = tmp;
}

#endif