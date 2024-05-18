/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:12:40 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 08:32:36 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Horde = zombieHorde(10, "Paco");
	for (int i = 0; i < 10; i++)
		Horde->announce();
	delete [] Horde;
}
