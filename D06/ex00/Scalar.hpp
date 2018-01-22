/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:19:48 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/17 14:00:35 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <climits>

class Scalar {

	public:

		class ImpossibleCastException : public std::exception {
			public:
				ImpossibleCastException() throw();
				ImpossibleCastException(ImpossibleCastException const &src) throw();
				virtual ~ImpossibleCastException() throw();

				ImpossibleCastException	&operator=(ImpossibleCastException const &rhs);
				virtual const char	*what(void) const throw();
		};

		class NonDisplayableException : public std::exception {
			public:
				NonDisplayableException() throw();
				NonDisplayableException(NonDisplayableException const &src) throw();
				virtual ~NonDisplayableException() throw();

				NonDisplayableException	&operator=(NonDisplayableException const &rhs);
				virtual const char	*what(void) const throw();
		};

		Scalar(void);
		Scalar(char *const val);
		Scalar(Scalar const &src);
		virtual ~Scalar(void);

		char	*getVal(void) const;
		operator char(void) const;
		operator int(void) const;
		operator float(void) const;

		Scalar		&operator=(Scalar const &rhs);

	private:

		char	*_val;

};

#endif