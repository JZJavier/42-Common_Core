/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:54:08 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/23 15:29:08 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
 
#include <iostream>

class Contact
{
	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _DarkestSecret;

	public:
		Contact() {}

		Contact(std::string FirstName, std::string LastName, std::string Nickname,
	std::string PhoneNumber, std::string DarkestSecret);

	//Setters
	void	SetFisrtName(std::string FirstName);
	void	SetLastName(std::string LastName);
	void	SetNickame(std::string Nickame);
	void	SetPhoneNumber(std::string PhoneNumber);
	void	SetDarkestSecret(std::string DarkestSecret);

	// Getters
	std::string	GetFisrtName();
	std::string	GetLastName();
	std::string	GetNickame();
	std::string	GetPhoneNumber();
	std::string	GetDarkestSecret();

};

#endif