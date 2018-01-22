/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:59:31 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 15:32:01 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

	public:
		Zombie();
		~Zombie();
		void					announce(void);
		std::string				getName(void);
		std::string				getType(void);
		void					setName(std::string name);
		void					setType(std::string type);
		static std::string		names[];
		static std::string		types[];

	private:
		std::string	_name;
		std::string _type;
};

#endif