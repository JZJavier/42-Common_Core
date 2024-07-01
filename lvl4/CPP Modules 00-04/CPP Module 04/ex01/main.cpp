/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 11:20:40 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

    Dog* test1 = new Dog();
    delete test1;

    Dog* dog1 = dynamic_cast<Dog*>(animals[0]);
    if (dog1) {
        dog1->makeSound();
        for (int i = 0; i < 100; ++i)
        {
            std::cout << "Idea " << i + 1 << ": " << dog1->getIdea(i) << std::endl;
        }
    }
    
    Cat* cat1 = dynamic_cast<Cat*>(animals[2]);
    if (cat1) {
        cat1->makeSound();
        for (int i = 0; i < 100; ++i)
        {
            std::cout << "Idea " << i + 1 << ": " << cat1->getIdea(i) << std::endl;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        delete animals[i];
    }

    return 0;
}

