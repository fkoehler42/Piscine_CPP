/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:41:59 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:50:33 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <string>
#include "Victim.hpp"

class Sorcerer {

	public:

		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		Sorcerer		&operator=(Sorcerer const &rhs);

		std::string				getName(void) const;
		std::string				getTitle(void) const;

		void					setName(std::string name);
		void					setTitle(std::string name);
		
		std::string				introduce(void) const;
		void					polymorph(Victim const &victim) const;

	private:

		Sorcerer(void);

		std::string				_name;
		std::string				_title;

};

std::ostream				&operator<<(std::ostream &os, Sorcerer const &rhs);

#endif