/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:50:50 by qduperon          #+#    #+#             */
/*   Updated: 2018/01/13 19:42:35 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AENTITY_HPP
#define AENTITY_HPP

#include <string>

class AEntity
{
public:

virtual void movement(void) = 0;

//Gets
int getX(void) const;
int getY(void) const;
char getSprite(void) const;

//Sets
void setX(int X);
void setY(int Y);
void setSprite(char Sprite);

protected:

int pX;
int pY;
char pSprite;

private:
};

#endif
