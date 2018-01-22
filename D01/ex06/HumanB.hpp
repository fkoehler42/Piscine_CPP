/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:30:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 22:07:00 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
#define HumanB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB();
		const std::string	getName(void) const;
		const Weapon		*getWeapon(void) const;
		void				attack(void) const;
		void				setWeapon(Weapon &weapon);

	private:
		const std::string	name;
		const Weapon		*weapon;		
};

#endif