/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:15:07 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 20:12:29 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int		main(int ac, char **av)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		buff;
	size_t			pos = 0;

	if (ac != 4) {
		std::cout << "Error, 3 and only 3 parameters required" << std::endl;
		return (1);
	}
	else if (!strlen(av[2])) {
		std::cout << "Error, the second argument can't be empty" << std::endl;
		return (1);
	}
	else {
		ifs.open(av[1], std::ifstream::in);
		if (ifs.fail()) {
			std::cout << "Error on file opening" << std::endl;
			return (1);
		}
		std::string		filename(av[1]);
		filename.append(".replace");
		ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
		if (ofs.fail()) {
			std::cout << "Error on file opening" << std::endl;
			return (1);
		}
		std::getline(ifs, buff, (char)ifs.eof());
		ifs.close();
		while ((pos = buff.find(av[2], pos)) != std::string::npos) {
			buff.replace(pos, strlen(av[2]), av[3]);
			pos += strlen(av[3]) + 1;
		}
		ofs << buff;
		ofs.close();
	}
	return (0);
}
