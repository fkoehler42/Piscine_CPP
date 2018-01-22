/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:45:02 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:28:38 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <string>
#include "Zombie.hpp"

class ZombieEvent {
	
	public:

		ZombieEvent();
		~ZombieEvent();
		void	randomChump(void);

	private:
		void	setZombieType(Zombie *zombie);
		Zombie	*newZombie(std::string name);	
};

#endif  