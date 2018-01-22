/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:27:39 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/15 14:53:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int		main(void) {
	Bureaucrat	roger("Roger", 150);
	Bureaucrat	bernard("Bernard", 1);
	Bureaucrat	tooLow("TooLow", 200);
	Bureaucrat	tooHigh("TooHigh", -10);

	std::cout << std::endl << roger << std::endl;
	std::cout << bernard << std::endl << std::endl;

	roger.decrementGrade();
	bernard.incrementGrade();

	for (size_t i = 0; i < 149; i++)
		roger.incrementGrade();
	std::cout << std::endl << roger << std::endl;
	
	return (0);
}