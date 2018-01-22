/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:29:35 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 20:05:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon {

	public:

		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(AWeapon const &src);
		virtual ~AWeapon(void);

		AWeapon			&operator=(AWeapon const &rhs);
		
		std::string		getName(void) const;
		int				getAPCost(void) const;
		int				getDamage(void) const;

		void			setName(std::string name);
		void			setAPCost(int apcost);
		void			setDamage(int damage);

		virtual void	attack(void) const = 0;

	private:

		AWeapon(void);
		
		std::string		_name;
		int				_apcost;
		int				_damage;
};

#endif

