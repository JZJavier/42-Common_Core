/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:49:45 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 18:26:14 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type)
{
	type = Type;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string Type)
{
	type = Type;
}

std::string&	Weapon::getType(void)
{
	return (type);
}
