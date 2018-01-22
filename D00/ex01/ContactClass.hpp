/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 19:55:09 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 21:20:15 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTCLASS_HPP
#define CONTACTCLASS_HPP

#include <iostream>

class Contact {

	public:

		Contact(void);
		~Contact(void);

		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_login(void) const;
		std::string	get_postal_addr(void) const;
		std::string	get_email_addr(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_birthday_date(void) const;
		std::string	get_favorite_meal(void) const;
		std::string	get_underwear_color(void) const;
		std::string	get_darkest_secret(void) const;

		void	fill_fields(void);
		void	print_contact_summary(int index) const;
		void	print_contact_infos(void) const;

	private:

		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_login;
		std::string	_postal_addr;
		std::string	_email_addr;
		std::string	_phone_number;
		std::string	_birthday_date;
		std::string	_favorite_meal;
		std::string	_underwear_color;
		std::string	_darkest_secret;

};

#endif
