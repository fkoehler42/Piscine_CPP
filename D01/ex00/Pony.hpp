/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:41:45 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/08 19:58:51 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

class Pony {
	
	public:
	
		Pony(int power);
		~Pony(void);

		int		getMagicalPower(void) const;
		void	saveTheWorld(void) const;

	private:

		int		_magicalPower;
};

#endif 