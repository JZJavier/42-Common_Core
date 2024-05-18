/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:58:51 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/05/17 08:33:15 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
	    // Default constructor
    	Zombie();

	    // Parameterized constructor
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);

};

// Creates horde of zombies
Zombie*	zombieHorde(int N, std::string name);

#endif