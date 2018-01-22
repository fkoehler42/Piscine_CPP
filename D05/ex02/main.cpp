/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:27:39 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:15:03 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main(void) {
	Bureaucrat	roger("Roger", 150);
	Bureaucrat	bernard("Bernard", 1);

	ShrubberyCreationForm		home("Home");
	RobotomyRequestForm			vog("Vogotron_21B");
	PresidentialPardonForm		zafod("Zafod");

	std::cout << std::endl << "//////// Shrubbery Form stuffs ////////" << std::endl;
	std::cout << std::endl << home << std::endl;
	roger.executeForm(home);
	bernard.signForm(home);
	bernard.executeForm(home);
	
	std::cout << std::endl << "//////// Robotomy Form stuffs ////////" << std::endl;
	std::cout << std::endl << vog << std::endl;
	bernard.signForm(vog);
	roger.executeForm(vog);
	bernard.executeForm(vog);

	std::cout << std::endl << "//////// Presidential Form stuffs ////////" << std::endl;
	std::cout << std::endl << zafod << std::endl;
	bernard.signForm(zafod);
	roger.executeForm(zafod);
	bernard.executeForm(zafod);

	return (0);
}