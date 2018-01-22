/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:10:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/11 19:39:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	public:

		FragTrap(std::string const name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap		&operator=(FragTrap const &rhs);

		void			vaulthunterDotExe(std::string const & target);

	private:

		FragTrap(void);
		void			_log(void) const;

		static unsigned int const	_specialAttackDmg;
		static unsigned int const	_specialAttackCost;
		static std::string const	_specialAttacks[];
};

#endif