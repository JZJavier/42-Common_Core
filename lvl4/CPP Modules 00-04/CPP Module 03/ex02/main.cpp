/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 07:23:03 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Juan");
    FragTrap frag2("Paco");
    FragTrap frag3 = frag1;

    frag1.attack("JordiPuyol");
    frag1.takeDamage(5);
    frag1.beRepaired(3);

    frag2.SetName("Paco");

    frag2.attack("Andreu");
    frag2.takeDamage(11);
    frag2.beRepaired(4);
    frag2.highFivesGuys();
    
    return 0;
}