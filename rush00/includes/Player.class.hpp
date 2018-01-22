/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:56:13 by qduperon          #+#    #+#             */
/*   Updated: 2018/01/14 18:36:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include <string>
#include "AEntity.class.hpp"
#include "Projectil.class.hpp"

class Player : public AEntity
{
public:

Player(void);
~Player(void);
Player(std::string name);
Player(Player const &src);

Player &operator=(Player const & rhs);

int        handleInput(int input);

//Gets
std::string   getName(void) const;
int           getHP(void) const;
Projectil     **getProjectils(void) const;
int           getScore(void) const;
void          incrementScore();
void          decrementScore();

//Heritage
virtual void movement(void);

protected:

private:
  std::string   _Name;
  int           _HP;
  Projectil     **_projectils;
  int  _score;
};

#endif
