/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectil.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:26:36 by qduperon          #+#    #+#             */
/*   Updated: 2018/01/13 21:48:54 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIL_CLASS_HPP
#define PROJECTIL_CLASS_HPP

#include "AEntity.class.hpp"

class Projectil : public AEntity
{
public:

Projectil(void);
Projectil(int PlayerX, int PlayerY);
~Projectil(void);
Projectil(Projectil const &src);

Projectil &operator=(Projectil const &rhs);

//Heritage
virtual void movement(void);

protected:

private:
};

#endif
