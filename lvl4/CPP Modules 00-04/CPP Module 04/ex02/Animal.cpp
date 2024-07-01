/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/07/01 11:05:11 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("void")
{
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destrucor Called" << std::endl;
}

Animal::Animal(std::string type): type(type)
{
    std::cout << "Animal Constructor Called: " << type << std::endl;
}

Animal::Animal(const Animal &obj): type(obj.type)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << "Animal Assignment Operator Called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

std::string Animal::getType(void) const
{
    return type;
}
    
void Animal::makeSound() const
{
    std::cout << "Sound" << std::endl;
}

void Animal::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}

std::string Animal::getIdea(int index) const
{
    return brain->getIdea(index);
}