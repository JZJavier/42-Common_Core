/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:23 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/30 16:57:07 by jjuarez-         ###   ########.fr       */
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
    void SetName(std::string name);
    std::string GetName();
    int GetHitPoints();
    int GetEnergyPoints();
    int GetAttackDamage();
};

#endif