/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:23 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/30 16:57:07 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog:public Animal
{
private:
    std::string type;
    Brain *brain;

public:
    Dog();
    Dog(const Dog &obj);
    Dog&		operator=(const Dog &obj);
    ~Dog();
    void makeSound() const;
    std::string getIdea(int index) const;
};

#endif