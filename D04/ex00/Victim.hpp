/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:41:59 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:13:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>

class Victim {

	public:

		Victim(std::string name);
		Victim(Victim const &src);
		virtual ~Victim(void);

		Victim		&operator=(Victim const &rhs);

		std::string				getName(void) const;

		void					setName(std::string name);
		
		std::string				introduce(void) const;
		virtual void			getPolymorphed(void) const;

	private:

		Victim(void);

		std::string				_name;

};

std::ostream				&operator<<(std::ostream &os, Victim const &rhs);

#endif