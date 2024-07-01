/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 10:23:27 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

	delete meta;
	delete j;
	delete i;
    
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* j2 = new WrongCat();
    const WrongAnimal* i2 = new WrongCat();

    std::cout << j2->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;

    i2->makeSound(); // Will output the WrongAnimal sound
    j2->makeSound(); // Will also output the WrongAnimal sound
    meta2->makeSound(); // Will output the WrongAnimal sound

    delete meta2;
    delete j2;
    delete i2;

	return 0;
}