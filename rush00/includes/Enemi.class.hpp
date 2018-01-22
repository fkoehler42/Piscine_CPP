/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemi.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:54:15 by qduperon          #+#    #+#             */
/*   Updated: 2018/01/14 11:09:35 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMI_CLASS_HPP
#define ENEMI_CLASS_HPP

#include "AEntity.class.hpp"
#include <string>

class Enemi : public AEntity
{
public:

Enemi(void);
Enemi(int X, int Y);
~Enemi(void);
Enemi(Enemi const &src);

Enemi &operator=(Enemi const &rhs);

//Gets
int 		getHP(void) const;
std::string	getColor(void) const;
int 		getSpeed(void) const;

//Sets
void setHP(int HP);
void setColor(std::string Color);
void setSpeed(int Speed);

//Heritage
virtual void movement(void);

protected:

std::string pColor;
int pHP;
int pSpeed;

private:

};

#endif
