/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectil.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:36:54 by qduperon          #+#    #+#             */
/*   Updated: 2018/01/13 22:05:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Projectil.class.hpp"

//construtor + Destructor
Projectil::Projectil(void) {
  this->pX = 0;
  this->pY = 0;
  this->pSprite = '|';
}
Projectil::~Projectil(void) {}
Projectil::Projectil(int PlayerX, int PlayerY) {
  this->pX = PlayerX;
  this->pY = PlayerY - 1;
  this->pSprite = '|';
}
Projectil::Projectil(Projectil const &src) { *this = src; }

//operator
Projectil &Projectil::operator=(Projectil const &rhs)
{
  this->pX = rhs.getX();
  this->pY = rhs.getY();
  this->pSprite = rhs.getSprite();
  return *this;
}

//Heritage
void Projectil::movement(void) {}
