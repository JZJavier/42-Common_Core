/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:49:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 18:48:06 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon): name(Name), weapon(Weapon)
{
	std::cout << "HumanA" << name << " constructed with " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA " << name << " destructed" << std::endl;
}

void	HumanA::attack()
{
    std::cout << name << " attacks with " << weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon Weapon)
{
    weapon = Weapon;
}
