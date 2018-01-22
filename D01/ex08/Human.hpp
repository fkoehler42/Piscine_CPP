/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:41:07 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/10 15:55:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>

class Human {

    public:
        Human(void);
        ~Human(void);
        void        action(std::string const & action_name, std::string const & target);

    private:
        void        meleeAttack(std::string const & target);
        void        rangedAttack(std::string const & target);
        void        intimidatingShout(std::string const & target);
        void        (Human::*actionPtr[3])(std::string const & target);
        void        initActionPtr(void);
        void        initCmpArray(void);
        std::string cmpArray[3];
};

#endif