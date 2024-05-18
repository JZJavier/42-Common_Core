/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:49:53 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 18:43:54 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string name;
	Weapon		&weapon;
public:
	HumanA(std::string Name, Weapon &Weapon);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon weapon);
};

#endif