/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 09:23:12 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destrucor Called" << std::endl;
}

Dog::Dog(const Dog &obj): Animal(obj.type)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    brain = new Brain(*obj.brain);
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog Assignment Operator Called" << std::endl;
    if (this != &obj) {
        Animal::operator=(obj);
        delete brain;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "gua gua" << std::endl;
}

std::string Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}