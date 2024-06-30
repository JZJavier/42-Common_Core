/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/30 17:58:50 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("void"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destrucor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "ClapTrap Constructor Called: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap Assignment Operator Called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
        _HitPoints = obj._HitPoints;
        _EnergyPoints = obj._EnergyPoints;
        _AttackDamage = obj._AttackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (_HitPoints > 0 && _EnergyPoints > 0)
    {
        _EnergyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " cannot attack, no hit points or energy points left." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _HitPoints -= amount;
    if (_HitPoints < 0)
        _HitPoints = 0;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _HitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_HitPoints > 0 && _EnergyPoints > 0)
    {
        _EnergyPoints--;
        _HitPoints += amount;
        std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points! Current hit points: " << _HitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " cannot be repaired, no hit points or energy points left." << std::endl;
    }
}

void ClapTrap::SetName(std::string name)
{
    _name = name;
}

std::string ClapTrap::GetName()
{
    return _name;
}

int ClapTrap::GetHitPoints()
{
    return _HitPoints;
}

int ClapTrap::GetEnergyPoints()
{
    return _EnergyPoints;
}

int ClapTrap::GetAttackDamage()
{
    return _AttackDamage;
}