/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:54:11 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/20 13:13:58 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string FirstName, std::string LastName, std::string Nickname,
	std::string PhoneNumber, std::string DarkestSecret)
{
	_FirstName = FirstName;
	_LastName = LastName;
	_Nickname = Nickname;
	_PhoneNumber = PhoneNumber;
	_DarkestSecret = DarkestSecret;
}

//Setters

void	Contact::SetFisrtName(std::string FirstName)
{
	_FirstName = FirstName;
}

void	Contact::SetLastName(std::string LastName)
{
	_LastName = LastName;
}

void	Contact::SetNickame(std::string Nickame)
{
	_Nickname = Nickame;
}

void	Contact::SetPhoneNumber(std::string PhoneNumber)
{
	_PhoneNumber = PhoneNumber;
}

void	Contact::SetDarkestSecret(std::string DarkestSecret)
{
	_DarkestSecret = DarkestSecret;
}

//Getters

std::string Contact::GetFisrtName()
{
	return (Contact::_FirstName);
}

std::string Contact::GetLastName()
{
	return (Contact::_LastName);
}

std::string Contact::GetNickame()
{
	return (Contact::_Nickname);
}

std::string Contact::GetPhoneNumber()
{
	return (Contact::_PhoneNumber);
}

std::string Contact::GetDarkestSecret()
{
	return (Contact::_DarkestSecret);
}

// int	main()
// {
// 	Contact	contact("Javier", "Juárez", "Javi", "-12345", "illooooo");

// 	std::cout << contact.GetFisrtName() << std::endl;
// 	std::cout << contact.GetLastName() << std::endl;
// 	std::cout << contact.GetNickame() << std::endl;
// 	std::cout << contact.GetPhoneNumber() << std::endl;
// 	std::cout << contact.GetDarkestSecret() << std::endl;

// 	return (0);
// }
