/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/30 18:00:54 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Juan");
    ClapTrap clap2("Paco");
    ClapTrap clap3 = clap1;

    clap1.attack("JordiPuyol");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    clap2.SetName("Paco");

    clap2.attack("Andreu");
    clap2.takeDamage(11);
    clap2.beRepaired(4);

    ClapTrap clap4;
    clap4 = clap2;
    
    return 0;
}