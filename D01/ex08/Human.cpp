/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:50:12 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 15:55:51 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

Human::Human(void) {
    initActionPtr();
    initCmpArray();
    return;
}

Human::~Human(void) { return; }

void    Human::action(std::string const & action_name, std::string const & target) {
    for (int i = 0; i < 3; ++i) {
        if (cmpArray[i] == action_name) {
            (this->*actionPtr[i])(target);
			return;
        }
    }
    std::cout << "[" << action_name << "] is not a referenced action of Human !" << std::endl;
    return;
}

void    Human::initActionPtr(void) {
    Human::actionPtr[0] = &Human::meleeAttack;
    Human::actionPtr[1] = &Human::rangedAttack;
    Human::actionPtr[2] = &Human::intimidatingShout;
    return;
}

void    Human::initCmpArray(void) {
     Human::cmpArray[0] = "meleeAttack";
     Human::cmpArray[1] = "rangedAttack";
     Human::cmpArray[2] = "intimidatingShout";
     return;
}

void    Human::meleeAttack(std::string const & target) {
    std::cout << "Human: Melee Attack -> " << target << std::endl;
    return;
}

void    Human::rangedAttack(std::string const & target) {
    std::cout << "Human: Ranged Attack -> " << target << std::endl;
    return;    
}

void    Human::intimidatingShout(std::string const & target) {
    std::cout << "Human: Intimidating Shout -> " << target << std::endl;
    return;
}