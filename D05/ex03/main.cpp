/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:27:39 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 18:46:57 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int		main(void) {

	Bureaucrat	roger("Roger", 10);
	AForm		*form;				
	Intern		intern;

	std::cout << std::endl << "//////// Intern stuffs ////////" << std::endl << std::endl;

	form = intern.makeForm("robotomy request", "Bender");
	roger.signForm(*form);
	delete form;
	
	form = intern.makeForm("shrubberycreation", "Forest");
	roger.signForm(*form);
	delete form;

	form = intern.makeForm("presidential pardon", "Zafod");
	roger.executeForm(*form);
	delete form;

	form = intern.makeForm("some shit", "stuffs");

	return (0);
}