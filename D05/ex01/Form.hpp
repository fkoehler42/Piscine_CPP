/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:48:20 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:17:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:

	class GradeTooHighException : public std::exception {
		public:
			GradeTooHighException() throw();
			GradeTooHighException(GradeTooHighException const &src) throw();
			virtual ~GradeTooHighException() throw();

			GradeTooHighException	&operator=(GradeTooHighException const &rhs);
			virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			GradeTooLowException() throw();
			GradeTooLowException(GradeTooLowException const &src) throw();
			virtual ~GradeTooLowException() throw();

			GradeTooLowException	&operator=(GradeTooLowException const &rhs);
			virtual const char	*what(void) const throw();
	};

		Form(void);
		Form(std::string const name, int const signGrade, int const execGrade);
		Form(Form const &src);
		virtual ~Form(void);

		Form				&operator=(Form const &rhs);

		std::string const	&getName(void) const;
		int const			&getSignGrade(void) const;
		int const			&getExecGrade(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(Bureaucrat &bureaucrat);

	private:
	
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;

};

std::ostream	&operator<<(std::ostream &os, Form const &rhs);

#endif
