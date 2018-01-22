/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 11:27:42 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/15 19:49:30 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

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
	
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		virtual ~Bureaucrat(void);

		Bureaucrat			&operator=(Bureaucrat const &rhs);

		std::string const	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int name);

		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(Form &form);

	private:

		std::string const	_name;
		int 				_grade;

};

std::ostream				&operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif
