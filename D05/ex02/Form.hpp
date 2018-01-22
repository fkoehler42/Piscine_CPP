/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:48:20 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/16 17:05:40 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

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

	class NotSignedException : public std::exception {
		public:
			NotSignedException() throw();
			NotSignedException(NotSignedException const &src) throw();
			virtual ~NotSignedException() throw();

			NotSignedException	&operator=(NotSignedException const &rhs);
			virtual const char	*what(void) const throw();
	};

		AForm(void);
		AForm(std::string const name, int const signGrade, int const execGrade);
		AForm(AForm const &src);
		virtual ~AForm(void);

		AForm				&operator=(AForm const &rhs);

		std::string const	&getName(void) const;
		int const			&getSignGrade(void) const;
		int const			&getExecGrade(void) const;
		bool				getIsSigned(void) const;

		void				beSigned(Bureaucrat &executor);
		virtual void		execute(Bureaucrat const &executor) const = 0;

	protected:

		void				checkExecution(Bureaucrat const &bureaucrat) const;

	private:
	
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;

};

std::ostream	&operator<<(std::ostream &os, AForm const &rhs);

#endif
