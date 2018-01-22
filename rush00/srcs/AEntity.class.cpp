/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:57:14 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/13 19:42:54 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AEntity.class.hpp"

//Gets
int AEntity::getX(void) const { return this->pX; }
int AEntity::getY(void) const { return this->pY; }
char AEntity::getSprite(void) const { return this->pSprite; }

//Sets
void AEntity::setX(int X) { this->pX = X; }
void AEntity::setY(int Y) { this->pY = Y; }
void AEntity::setSprite(char Sprite) { this->pSprite = Sprite; }
