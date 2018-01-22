/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:21:21 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/19 18:55:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "mutantStack.hpp"

int main(void) {
	MutantStack<int> mstack;
	MutantStack<int>::iterator it;
	MutantStack<int>::iterator ite;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "stack top : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "stack size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	it = mstack.begin();
	ite = mstack.end();
	
	++it;
	--it;

	std::cout << "stack content : ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl << std::endl;
	
	std::stack<int> copy(mstack);

	copy.pop();

	std::cout << "original stack top : " << mstack.top() << ", size : " << mstack.size() << std::endl;
	std::cout << "copied as std::stack top (after a pop() call) : " << copy.top() << ", size : " << copy.size() << std::endl;

	MutantStack<int> copy2(mstack);

	copy2.push(42);

	it = copy2.begin();
	ite = copy2.end();

	std::cout << "copied as Mutant stack content (after a push(42)) : ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << ", size : " << copy2.size() << std::endl;

	return 0;
}