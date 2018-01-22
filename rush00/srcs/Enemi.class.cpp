/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemi.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduperon <qduperon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:00:07 by qduperon          #+#    #+#             */
/*   Updated: 2018/01/14 11:09:14 by qduperon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Enemi.class.hpp"
#include "../includes/Game.class.hpp"

//construtor + Destructor
Enemi::Enemi(void) : pHP(0), pColor("white") {
  this->pX = rand() % (MAP_SIZE - 2);
  this->pY = 0;
  this->pSprite = 'W';
}
Enemi::~Enemi(void) {}
Enemi::Enemi(int X, int Y) : pHP(0), pColor("white") {
  this->pX = X;
  this->pY = Y;
  this->pSprite = 'W';
}
Enemi::Enemi(Enemi const &src) { *this = src; }

//operator
Enemi &Enemi::operator=(Enemi const &rhs)
{
  this->pX = rhs.getX();
  this->pY = rhs.getY();
  this->pHP = rhs.getHP();
  return *this;
}

//Gets
int         Enemi::getHP(void) const { return this->pHP; }
std::string Enemi::getColor(void) const { return this->pColor; }
int         Enemi::getSpeed(void) const { return this->pSpeed; }

//Sets
void Enemi::setHP(int HP) { this->pHP = HP; }
void Enemi::setColor(std::string Color) { this->pColor = Color; }
void Enemi::setSpeed(int Speed) { this->pSpeed = Speed; }

//Heritage
void Enemi::movement(void) {}
