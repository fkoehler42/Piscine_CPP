/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:10:11 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 17:07:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {

	public:

		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap		&operator=(ClapTrap const &rhs);

		unsigned int	getHitPoints(void) const;
		unsigned int	getMaxHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getMaxEnergyPoints(void) const;
		unsigned int	getLevel(void) const;
		unsigned int	getMeleeAttackDmg(void) const;
		unsigned int	getRangedAttackDmg(void) const;
		unsigned int	getArmorDmgReduction(void) const;
		std::string		getName(void) const;

		void			setHitPoints(unsigned int n);
		void			setMaxHitPoints(unsigned int n);
		void			setEnergyPoints(unsigned int n);
		void			setMaxEnergyPoints(unsigned int n);
		void			setLevel(unsigned int n);
		void			setMeleeAttackDmg(unsigned int n);
		void			setRangedAttackDmg(unsigned int n);
		void			setArmorDmgReduction(unsigned int n);
		void			setName(std::string name);

		void			meleeAttack(std::string const &target);
		void			rangedAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

	protected:

		ClapTrap(void);
		void			_log(void) const;

		unsigned int				_hitPoints;
		unsigned int				_maxHitPoints;
		unsigned int				_energyPoints;
		unsigned int				_maxEnergyPoints;
		unsigned int				_level;
		unsigned int				_meleeAttackDmg;
		unsigned int				_rangedAttackDmg;
		unsigned int				_armorDmgReduction;
		std::string					_name;
};

#endif