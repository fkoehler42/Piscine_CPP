/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:46:03 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 17:57:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDCLASS_HPP
#define FIXEDCLASS_HPP

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed		&operator=(Fixed const &rhs);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
	
		int					_rawValue;
		static const int	_fractionalBits;
};

#endif