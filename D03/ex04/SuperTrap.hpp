/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:10:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/11 19:39:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

	public:

		SuperTrap(std::string const name);
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);

		SuperTrap		&operator=(SuperTrap const &rhs);

		void			meleeAttack(std::string const &target);
		void			rangedAttack(std::string const &target);

	private:

		SuperTrap(void);
		void			_log(void) const;
};

#endif