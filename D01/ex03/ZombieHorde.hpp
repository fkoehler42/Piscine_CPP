/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:54:34 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:09:08 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {

	public:
		ZombieHorde(int n);
		~ZombieHorde(void);
		void	announce(void) const;

	private:
		void	_setHorde(int n);
		Zombie *_getHorde(void) const;
		Zombie	*_horde;
		int		_nb_zombies;
};

#endif