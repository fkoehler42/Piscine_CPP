/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:41:59 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:13:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include <string>
#include "Victim.hpp"

class Peon : public Victim{

	public:

		Peon(std::string name);
		Peon(Peon const &src);
		virtual ~Peon(void);

		Peon		&operator=(Peon const &rhs);

		virtual void			getPolymorphed(void) const;

	private:

		Peon(void);

		std::string				_name;

};

std::ostream				&operator<<(std::ostream &os, Peon const &rhs);

#endif