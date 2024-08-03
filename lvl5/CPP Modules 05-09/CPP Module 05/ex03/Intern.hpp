/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:39:41 by javier            #+#    #+#             */
/*   Updated: 2024/08/03 19:12:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *createShrubberyCreationForm(const std::string& target) const;
		AForm *createRobotomyRequestForm(const std::string& target) const;
		AForm *createPresidentialPardonForm(const std::string& target) const;
	public:
		Intern();
		Intern(const Intern &copy);
		virtual ~Intern();
		Intern &operator=(const Intern &copy);

		AForm *makeForm(std::string form, std::string target);
};

#endif