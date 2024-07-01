/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:23 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 07:04:10 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string> 

#ifndef SCRAVTRAP
#define SCARVTRAP

#include "ClapTrap.hpp"

class ScravTrap: public ClapTrap
{
public:
    ScravTrap();
    ScravTrap(std::string name);
    ScravTrap(const ScravTrap &obj);
    ScravTrap&		operator=(const ScravTrap &obj);
    ~ScravTrap();
    void attack(const std::string& target);
    void guardGate(void);
};

#endif
