/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:34:39 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/19 19:20:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

#define NB_INT 1000000

int main(void) {

//**** Custom settings ****//

	Span sp = Span(3);

	try {
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.addNumber(0);
		// sp.addNumber(42); // overflow check


//**** Random creation of NB_INT values ****//

		// Span sp = Span(NB_INT);

		// srand(time(NULL));
		// for (size_t i = 0; i < NB_INT; i++)
		// 	sp.addNumber(rand() % INT_MAX);

		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
	} catch (std::exception const &ex) {
		std::cout << "`Span class` : Error : " << ex.what() << std::endl;
	}
}
