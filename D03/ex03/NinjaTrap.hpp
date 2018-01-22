/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:10:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/11 19:39:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

	public:

		NinjaTrap(std::string const name);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap		&operator=(NinjaTrap const &rhs);

		void			ninjaShoeBox(NinjaTrap const &target) const;
		void			ninjaShoeBox(FragTrap const &target) const;
		void			ninjaShoeBox(ScavTrap const &target) const;
		void			ninjaShoeBox(ClapTrap const &target) const;

	private:

		NinjaTrap(void);
		void			_log(void) const;
};

#endif