/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 15:40:08 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/19 18:51:21 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

	public:

		MutantStack<T>(void) {}
		MutantStack<T>(MutantStack const &src) { *this = src; }
		~MutantStack<T>(void) {}

		MutantStack		&operator=(MutantStack const &rhs) { this->c = rhs.c; return *this; }

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator		begin() { return std::stack<T>::c.begin(); }
		iterator		end() { return std::stack<T>::c.end(); }

	private:
};


#endif