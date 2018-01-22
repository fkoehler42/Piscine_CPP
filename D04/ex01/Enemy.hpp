/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:30:12 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 20:39:48 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy {

	public:

		Enemy(int hp, std::string const &type);
		Enemy(Enemy const &src);
		virtual ~Enemy(void);

		Enemy			&operator=(Enemy const &rhs);

		std::string		getType(void) const;
		int				getHP(void) const;

		void			setType(std::string const type);
		void			setHP(int hp);

		virtual void	takeDamage(int);

	private:

		Enemy(void);
		
		std::string		_type;
		int				_hp;
};

#endif