/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:59:51 by javier            #+#    #+#             */
/*   Updated: 2024/08/02 09:34:18 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat paco("Paco", 2);
		Bureaucrat illo("Illo", 149);
		Form form("Independenzia", 2, 2);
		Form form2("Independenzia2", 150, 150);
		paco.signForm(form);
		paco.incrementGrade();
		paco.signForm(form);
		illo.signForm(form2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}