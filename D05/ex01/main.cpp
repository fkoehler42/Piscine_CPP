/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:27:39 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/15 19:56:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main(void) {
	Bureaucrat	roger("Roger", 150);
	Bureaucrat	bernard("Bernard", 1);
	Bureaucrat	tooLowBureaucrat("TooLow", 200);
	Bureaucrat	tooHighBureaucrat("TooHigh", -10);

	Form		visa("visa", 1, 10);
	Form		ft("42 registration", 42, 150);
	Form		tooLowForm("TooLowForm", 65, 151);
	Form		tooHighForm("TooHighForm", 0, 50);

	std::cout << std::endl << "//////// Bureaucrat stuffs ////////" << std::endl;
	std::cout << std::endl << roger << std::endl;
	std::cout << bernard << std::endl << std::endl;

	roger.decrementGrade();
	bernard.incrementGrade();

	for (size_t i = 0; i < 149; i++)
		roger.incrementGrade();
	roger.setGrade(42);
	std::cout << std::endl << roger << std::endl;
	
	std::cout << std::endl << "//////// Form stuffs ////////" << std::endl;
	std::cout << std::endl << ft << std::endl;
	roger.signForm(visa);
	roger.signForm(ft);
	bernard.signForm(ft);
	std::cout << ft << std::endl;

	return (0);
}