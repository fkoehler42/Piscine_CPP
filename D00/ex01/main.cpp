/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:10:51 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/08 18:23:24 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "ContactClass.cpp"

#define PHONEBOOK_SIZE 8

void	display_contacts_list(Contact list[])
{
	int	i = 0;
	std::cout << std::endl << std::right << std::setw(COL_WIDTH) << "Index" << '|'
	<< std::right << std::setw(COL_WIDTH) << "First name" << '|'
	<< std::right << std::setw(COL_WIDTH) << "Last name" << '|'
	<< std::right << std::setw(COL_WIDTH) << "Nickname" << std::endl;
	while (i < PHONEBOOK_SIZE)
	{
		if (list[i].get_firstname() != "")
			list[i].print_contact_summary(i + 1);
		i++;
	}
	std::cout << std::endl;
}

void	display_contacts(Contact list[])
{
	int			i = 0;
	int			int_buffer = -1;
	std::string	buffer;

	if (list[i].get_firstname() == "")
	{
		std::cout << "No contact to display." << std::endl;
		return;
	}
	display_contacts_list(list);
	std::cout << std::endl << "Please choose an index to display contact informations : ";
	std::getline(std::cin, buffer);
	std::stringstream(buffer) >> int_buffer;
	while ((int_buffer < 1) || (int_buffer > PHONEBOOK_SIZE)
	|| (list[int_buffer - 1].get_firstname() == ""))
	{
		std::cout << "Bad input / No contact at this index, please try again : ";
		std::getline(std::cin, buffer);
		std::stringstream(buffer) >> int_buffer;
	}
	list[int_buffer - 1].print_contact_infos();
	return;
}

void	add_contact(Contact list[])
{
	int			i = 0;
	std::string	buffer;
	Contact		new_contact;

	while (i < PHONEBOOK_SIZE && (list[i].get_firstname() != ""))
		i++;
	if (i == PHONEBOOK_SIZE)
	{
		i = -1;
		std::cout << "Your phonebook is full, please choose an index to delete one"
		" of your contacts or enter any other input to abort :" << std::endl;
		display_contacts_list(list);
		std::getline(std::cin, buffer);
		std::stringstream(buffer) >> i;
		if ((i > 0) && (i <= PHONEBOOK_SIZE))
		{
			i--;
			list[i] = new_contact;
			std::cout << "Contact properly removed, you can now add a new one." << std::endl;
			list[i].fill_fields();
		}
		else
			std::cout << "No contact removed, going back to the menu." << std::endl;
	}
	else
		list[i].fill_fields();
	return;
}

int		main(void) {
	Contact		contacts_list[PHONEBOOK_SIZE];
	std::string	buffer;
	std::string actions = "Please choose one of the following actions : [ADD / SEARCH / EXIT]";

	std::cout << "Welcome into you personal phonebook !" << std::endl << actions << std::endl;
	while (true) {
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
			exit(EXIT_SUCCESS);
		else if (buffer == "ADD")
			add_contact(contacts_list);
		else if (buffer == "SEARCH")
			display_contacts(contacts_list);
		else
			std::cout << "Bad input. " << actions << std::endl;
	}
	return (0);
}
