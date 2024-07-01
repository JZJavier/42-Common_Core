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
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destrucor Called" << std::endl;
}

Dog::Dog(const Dog &obj): Animal(obj.type)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog Assignment Operator Called" << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "gua gua" << std::endl;
}