/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:39:51 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 20:12:40 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

	public:
		Weapon(std::string type);
		Weapon(void);
		~Weapon(void);
		const std::string	&getType(void) const;
		void				setType(std::string);

	private:
		std::string	type;
};

#endif