/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:46:03 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/11 12:31:32 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDCLASS_HPP
#define FIXEDCLASS_HPP

#include <ostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);

		Fixed				&operator=(Fixed const &rhs);
		bool				operator<(Fixed const &rhs);
		bool				operator>(Fixed const &rhs);
		bool				operator<=(Fixed const &rhs);
		bool				operator>=(Fixed const &rhs);
		bool				operator==(Fixed const &rhs);
		bool				operator!=(Fixed const &rhs);
		Fixed				operator+(Fixed const &rhs);
		Fixed				operator-(Fixed const &rhs);
		Fixed				operator*(Fixed const &rhs);
		Fixed				operator/(Fixed const &rhs);
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed const	&min(Fixed const &fixed1, Fixed const &fixed2);
		static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		static Fixed const	&max(Fixed const &fixed1, Fixed const &fixed2);

	private:

		static int			_powBits(int const nBits);
		int					_rawValue;
		static int const	_fractionalBits;
};

std::ostream				&operator<<(std::ostream &os, Fixed const &rhs);

#endif