/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:59:51 by javier            #+#    #+#             */
/*   Updated: 2024/08/02 17:46:19 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Bureaucrat paco("Paco", 2);
		Bureaucrat illo("Illo", 149);

		AForm *shrubbery = intern.makeForm("Shrubbery", "Shrubbery");
		AForm *robotomy = intern.makeForm("Robotomy", "Robotomy");
		AForm *presidential = intern.makeForm("Presidential", "Presidential");
		paco.signAForm(*shrubbery);
		paco.executeForm(*shrubbery);
		paco.executeForm(*robotomy);
		paco.executeForm(*presidential);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}