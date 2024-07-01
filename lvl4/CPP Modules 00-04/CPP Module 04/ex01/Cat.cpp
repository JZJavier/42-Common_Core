/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 09:23:12 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destrucor Called" << std::endl;
}

Cat::Cat(const Cat &obj): Animal(obj)
{
    brain = new Brain(*obj.brain);
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Cat Assignment Operator Called" << std::endl;
    if (this != &obj)
    {
        Animal::operator=(obj);
        delete brain;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "miauuuuuuuuu" << std::endl;
}

std::string Cat::getIdea(int index) const 
{
    return brain->getIdea(index);
}