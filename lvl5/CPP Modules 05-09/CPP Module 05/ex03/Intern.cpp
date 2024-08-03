/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:39:57 by javier            #+#    #+#             */
/*   Updated: 2024/08/03 19:12:33 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    typedef AForm* (Intern::*FunctionPtr)(std::string const& target) const;

    std::string forms[3] = {"Shrubbery", "Robotomy", "Presidential"};
    FunctionPtr functions[3] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
    
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == form)
            return (this->*functions[i])(target);
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}

AForm *Intern::createShrubberyCreationForm(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}