/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:23 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 06:59:56 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

#ifndef CLAPTRAP
#define CLAPTRAP

class ClapTrap
{
private:
    std::string _name;
    int _HitPoints;
    int _EnergyPoints;
    int _AttackDamage;
    
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &obj);
	ClapTrap&		operator=(const ClapTrap &obj);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void SetEnergyPoints(int EnergyPoints);
    void SetAttackDamage(int AttackDamage);
    void SetName(std::string name);
    void SetHitPoints(int HitPoints);
    std::string GetName();
    int GetHitPoints();
    int GetEnergyPoints();
    int GetAttackDamage();
};

#endif