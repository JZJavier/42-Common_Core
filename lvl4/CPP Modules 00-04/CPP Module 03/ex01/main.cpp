/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 07:15:25 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

int main()
{
    ScravTrap scrav1("Juan");
    ScravTrap scrav2("Paco");
    ScravTrap scrav3 = scrav1;

    scrav1.attack("JordiPuyol");
    scrav1.takeDamage(5);
    scrav1.beRepaired(3);

    scrav2.SetName("Paco");

    scrav2.attack("Andreu");
    scrav2.takeDamage(11);
    scrav2.beRepaired(4);
    scrav2.guardGate();
    
    return 0;
}