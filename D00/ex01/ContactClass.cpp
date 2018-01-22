/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:07:30 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/09 21:21:54 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "ContactClass.hpp"

#define COL_WIDTH 10

Contact::Contact(void) : _firstname(""), _lastname(""), _nickname(""), _login(""),
_postal_addr(""), _email_addr(""), _phone_number(""), _birthday_date(""),
_favorite_meal(""), _underwear_color(""), _darkest_secret("") {
	return;
}

Contact::~Contact(void) {
	return;
}

void	Contact::print_contact_summary(int index) const {
	std::cout << std::right << std::setw(COL_WIDTH) << index << '|';
	if (this->get_firstname().length() > COL_WIDTH)
		std::cout << std::right << std::setw(COL_WIDTH) << this->get_firstname().substr(0, 9).append(".");
	else
		std::cout << std::right << std::setw(COL_WIDTH) << this->get_firstname();
	std::cout << '|';
	if (this->get_lastname().length() > COL_WIDTH)
		std::cout << std::right << std::setw(COL_WIDTH) << this->get_lastname().substr(0, 9).append(".");
	else
		std::cout << std::right << std::setw(COL_WIDTH) << this->get_lastname();
	std::cout << '|';
	if (this->get_nickname().length() > COL_WIDTH)
		std::cout << std::right << std::setw(COL_WIDTH) << this->get_nickname().substr(0, 9).append(".") << std::endl;
	else
		std::cout << std::right << std::setw(COL_WIDTH) << this->get_nickname() << std::endl;
}

void	Contact::print_contact_infos() const {
	std::cout << "First name : " << this->get_firstname() << std::endl
	<< "Last name : " << this->get_lastname() << std::endl
	<< "nickname : " << this->get_nickname() << std::endl
	<< "login : " << this->get_login() << std::endl
	<< "Postal address : " << this->get_postal_addr() << std::endl
	<< "Email address : " << this->get_email_addr() << std::endl
	<< "Phone number : " << this->get_phone_number() << std::endl
	<< "Birthday date : " << this->get_birthday_date() << std::endl
	<< "Favorite meal : " << this->get_favorite_meal() << std::endl
	<< "Underwear color : " << this->get_underwear_color() << std::endl
	<< "Darkest secret : " << this->get_darkest_secret() << std::endl;
	return;
}

void	Contact::fill_fields(void) {
	while (this->get_firstname().find_first_not_of(" \t\n\v\f\r") == std::string::npos)
	{
		std::cout << "Please enter a first name(required) : ";
		std::getline(std::cin, this->_firstname);
	}
	while (this->get_lastname().find_first_not_of(" \t\n\v\f\r") == std::string::npos)
	{
		std::cout << "Please enter a last name(required) : ";
		std::getline(std::cin, this->_lastname);
	}
	while (this->get_nickname().find_first_not_of(" \t\n\v\f\r") == std::string::npos)
	{
		std::cout << "Please enter a nickname(required) : ";
		std::getline(std::cin, this->_nickname);
	}
	std::cout << "Please enter a login : ";
	std::getline(std::cin, this->_login);
	std::cout << "Please enter a postal address : ";
	std::getline(std::cin, this->_postal_addr);
	std::cout << "Please enter an email address : ";
	std::getline(std::cin, this->_email_addr);
	std::cout << "Please enter a phone number : ";
	std::getline(std::cin, this->_phone_number);
	std::cout << "Please enter a birthday date : ";
	std::getline(std::cin, this->_birthday_date);
	std::cout << "Please enter a favorite meal : ";
	std::getline(std::cin, this->_favorite_meal);
	std::cout << "Please enter an underwear color : ";
	std::getline(std::cin, this->_underwear_color);
	std::cout << "Please enter a darkest secret : ";
	std::getline(std::cin, this->_darkest_secret);
	std::cout << "New contact successfully added ("
	<< this->get_firstname() << " " << this->get_lastname() << ")" << std::endl;
}

std::string	Contact::get_firstname(void) const { return (this->_firstname); }
std::string	Contact::get_lastname(void) const { return (this->_lastname); }
std::string	Contact::get_nickname(void) const { return (this->_nickname); }
std::string	Contact::get_login(void) const { return (this->_login); }
std::string	Contact::get_postal_addr(void) const { return (this->_postal_addr); }
std::string	Contact::get_email_addr(void) const { return (this->_email_addr); }
std::string	Contact::get_phone_number(void) const { return (this->_phone_number); }
std::string	Contact::get_birthday_date(void) const { return (this->_birthday_date); }
std::string	Contact::get_favorite_meal(void) const { return (this->_favorite_meal); }
std::string	Contact::get_underwear_color(void) const { return (this->_underwear_color); }
std::string	Contact::get_darkest_secret(void) const { return (this->_darkest_secret); }
