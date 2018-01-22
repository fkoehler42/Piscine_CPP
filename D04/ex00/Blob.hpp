/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blob.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:41:59 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/12 18:13:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOB_HPP
#define BLOB_HPP

#include <string>
#include "Victim.hpp"

class Blob : public Victim{

	public:

		Blob(std::string name);
		Blob(Blob const &src);
		virtual ~Blob(void);

		Blob		&operator=(Blob const &rhs);

		virtual void			getPolymorphed(void) const;

	private:

		Blob(void);

		std::string				_name;

};

std::ostream				&operator<<(std::ostream &os, Blob const &rhs);

#endif