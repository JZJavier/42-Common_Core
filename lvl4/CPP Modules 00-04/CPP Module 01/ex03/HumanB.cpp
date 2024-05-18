/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:49:50 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 18:48:09 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name): weapon(NULL)
{
    name = Name;
	std::cout << "HumanB" << name << " constructed without a weapon" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << name << " destructed" << std::endl;
}

void	HumanB::attack()
{
    std::cout << name << " attacks with " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
    weapon = &Weapon;
}
