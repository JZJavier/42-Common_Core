/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 07:52:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/16 08:49:59 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Pointer to a ZOmbie object allocated with new
Zombie	*newZombie(std::string name);

// Create a Zombie on the heap
void	randomChump(std::string name);

int	main(void)
{
	Zombie *leak = newZombie("Leak");
	leak->announce();
	randomChump("Paco");
	delete leak;
	return (0);
}
