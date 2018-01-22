/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:59:31 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 14:45:26 by fkoehler         ###   ########.fr       */
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

	private:
		void				_setName(std::string name);
		void				_setType(std::string type);
		static std::string	_getRandName(void);
		static std::string	_getRandType(void);
		std::string			_name;
		std::string 		_type;
		static std::string	_names[];
		static std::string	_types[];
};

#endif