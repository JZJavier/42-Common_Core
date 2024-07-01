/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:29:23 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/30 16:57:07 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{
protected:
    std::string type;
    Brain *brain;
    
public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &obj);
    Animal&		operator=(const Animal &obj);
    virtual ~Animal();
    std::string getType(void) const;
    virtual void makeSound() const  = 0; // Pure virtual function

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif