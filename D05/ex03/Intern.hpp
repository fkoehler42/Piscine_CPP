/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:30:58 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:50:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

	public:

		class UnknownFormException : public std::exception {
			public:
				UnknownFormException() throw();
				UnknownFormException(UnknownFormException const &src) throw();
				virtual ~UnknownFormException() throw();

				UnknownFormException	&operator=(UnknownFormException const &rhs);
				virtual const char	*what(void) const throw();
		};

		Intern(void);
		Intern(Intern const &src);
		virtual ~Intern(void);

		Intern		&operator=(Intern const &rhs);
		AForm		*makeForm(std::string const formType, std::string const formName) const;

	private:
};


#endif