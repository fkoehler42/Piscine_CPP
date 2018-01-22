/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:02:17 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 22:02:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {

	public:

		Character(void);
		Character(std::string const &name);
		Character(Character const &src);
		~Character(void);

		Character		&operator=(Character const &rhs);

		std::string		getName(void) const;
		int				getAP(void) const;
		AWeapon			*getWeapon(void) const;
		std::string		getStats(void) const;
		
		void			setName(std::string name);
		void			setAP(int ap);

		void			recoverAP(void);
		void			equip(AWeapon* weapon);
		void			attack(Enemy* enemy);

	private:

		std::string		_name;
		int				_ap;
		AWeapon			*_weapon;

};

std::ostream			&operator<<(std::ostream &os, Character const &rhs);

#endif
