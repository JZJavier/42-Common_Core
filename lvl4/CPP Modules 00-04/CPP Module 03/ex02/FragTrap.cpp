/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 07:23:24 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    this->SetHitPoints(100);
    this->SetEnergyPoints(100);
    this->SetAttackDamage(30);
    std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destrucor Called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->SetName(name);
    this->SetHitPoints(100);
    this->SetEnergyPoints(100);
    this->SetAttackDamage(30);
    std::cout << "FragTrap Constructor Called: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj): ClapTrap(obj)
{
    std::cout << "FragTrap Copy Constructor Called" << std::endl;
    *this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
    std::cout << "FragTrap Assignment Operator Called" << std::endl;
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap High Five Guys" << std::endl;
}