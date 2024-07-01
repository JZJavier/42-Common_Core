/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/30 17:58:50 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

ScravTrap::ScravTrap(void)
{
    this->SetHitPoints(100);
    this->SetEnergyPoints(50);
    this->SetAttackDamage(20);
    std::cout << "ScravTrap Default Constructor Called" << std::endl;
}

ScravTrap::~ScravTrap()
{
    std::cout << "ScravTrap Destrucor Called" << std::endl;
}

ScravTrap::ScravTrap(std::string name)
{
    this->SetHitPoints(100);
    this->SetEnergyPoints(50);
    this->SetAttackDamage(20);
    std::cout << "ScravTrap Constructor Called: " << name << std::endl;
}

ScravTrap::ScravTrap(const ScravTrap &obj): ClapTrap(obj)
{
    std::cout << "ScravTrap Copy Constructor Called" << std::endl;
    *this = obj;
}

ScravTrap& ScravTrap::operator=(const ScravTrap &obj)
{
    std::cout << "ScravTrap Assignment Operator Called" << std::endl;
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return *this;
}

void ScravTrap::attack(const std::string& target)
{
    if (this->GetEnergyPoints() > 0)
    {
        this->SetEnergyPoints(this->GetEnergyPoints() - 1);
        std::cout << "ScravTrap " << this->GetName() << " attacks " << target << ", causing " << this->GetAttackDamage() << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ScravTrap " << this->GetName() << " cannot attack, no hit points or energy points left." << std::endl;
    }
}

void	ScravTrap::guardGate(void)
{
	std::cout << "ScavTrap changed to GuardGate mode." << std::endl;
}