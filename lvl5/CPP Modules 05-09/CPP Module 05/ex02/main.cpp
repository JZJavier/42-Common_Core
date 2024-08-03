/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:59:51 by javier            #+#    #+#             */
/*   Updated: 2024/08/02 17:36:44 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat paco("Paco", 2);
		Bureaucrat illo("Illo", 149);

		ShrubberyCreationForm shrubbery("Shrubbery");
		RobotomyRequestForm robotomy("Robotomy");
		PresidentialPardonForm presidential("Presidential");
		paco.signAForm(shrubbery);
		paco.executeForm(shrubbery);
		paco.executeForm(robotomy);
		paco.executeForm(presidential);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}