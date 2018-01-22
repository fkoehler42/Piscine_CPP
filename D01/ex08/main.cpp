/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 09:51:12 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 15:57:50 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void) {
    Human   human;

    human.action("meleeAttack", "Toto");
    human.action("rangedAttack", "Titi");
    human.action("intimidatingShout", "Tutu");
    return (0);
}