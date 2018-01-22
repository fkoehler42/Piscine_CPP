/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:46:03 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 19:26:50 by fkoehler         ###   ########.fr       */
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

		Fixed		&operator=(Fixed const &rhs);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;

	private:

		static int			_powBits(int const nBits);
		int					_rawValue;
		static int const	_fractionalBits;
};

std::ostream				&operator<<(std::ostream &os, Fixed const &rhs);

#endif