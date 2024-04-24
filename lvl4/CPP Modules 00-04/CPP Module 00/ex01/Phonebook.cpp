/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:19:21 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/23 19:06:28 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	_NumContacts = 0;
}

bool isNumeric(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}


void Phonebook::AddContact()
{
	if (_NumContacts < 8)
	{
		Contact NewContact;

		// Prompt the user for contact details
		std::string FirstName, LastName, Nickname, PhoneNumber, DarkestSecret;
		std::cout << "First name: ";
		std::cin >> FirstName;
		NewContact.SetFisrtName(FirstName);

		std::cout << "Last name: ";
		std::cin >> LastName;
		NewContact.SetLastName(LastName);

		std::cout << "Nickname: ";
		std::cin >> Nickname;
		NewContact.SetNickame(Nickname);

		bool isValidPhoneNumber = false;
		while (!isValidPhoneNumber)
		{
			std::cout << "Enter phone number (digits only): ";
			std::cin >> PhoneNumber;

			isValidPhoneNumber = isNumeric(PhoneNumber);
			if (!isValidPhoneNumber)
				std::cout << "Invalid phone number. Please enter digits only." << std::endl;
		}
		NewContact.SetPhoneNumber(PhoneNumber);

		std::cout << "Darkest secret: ";
		std::cin >> DarkestSecret;
		NewContact.SetDarkestSecret(DarkestSecret);

		// Add the new contact to the end of the array
		_Contacts[_NumContacts++] = NewContact;
	}
	else
	{
		// If the array is full, overwrite the oldest contact
		// By shifting all contacts one position to the left
		for (int i = 0; i < 7; ++i)
			_Contacts[i] = _Contacts[i + 1];

		std::string FirstName, LastName, Nickname, PhoneNumber, DarkestSecret;
		std::cout << "First name: ";
		std::cin >> FirstName;
		_Contacts[7].SetFisrtName(FirstName);

		std::cout << "Last name: ";
		std::cin >> LastName;
		_Contacts[7].SetLastName(LastName);

		std::cout << "Nickname: ";
		std::cin >> Nickname;
		_Contacts[7].SetNickame(Nickname);

		bool isValidPhoneNumber = false;
		while (!isValidPhoneNumber)
		{
			std::cout << "Enter phone number (digits only): ";
			std::cin >> PhoneNumber;

			isValidPhoneNumber = isNumeric(PhoneNumber);
			if (!isValidPhoneNumber) {
				std::cout << "Invalid phone number. Please enter digits only." << std::endl;
			}
		}
		_Contacts[7].SetPhoneNumber(PhoneNumber);

		std::cout << "Darkest secret: ";
		std::cin >> DarkestSecret;
		_Contacts[7].SetDarkestSecret(DarkestSecret);
	}
}

void Phonebook::DisplayContacts()
{
	std::cout << std::setw(10) << "INDEX" << "|"
			  << std::setw(10) << "FIRST NAME" << "|"
			  << std::setw(10) << "LAST NAME" << "|"
			  << std::setw(10) << "NICKNAME" << std::endl;

	for (int i = 0; i < _NumContacts; ++i)
	{
		std::cout << std::setw(10) << i + 1 << "|"
				<< std::setw(10) << TruncateString(_Contacts[i].GetFisrtName()) << "|"
				<< std::setw(10) << TruncateString(_Contacts[i].GetLastName()) << "|"
				<< std::setw(10) << TruncateString(_Contacts[i].GetNickame()) << std::endl;
	}

	// Clear input buffer

	// clear() is used to clear any error flags that may be set on the input stram
	std::cin.clear();
	// ignore() is used to discard any remaining characters in the input buffer until a newline character is encountered. 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	
	std::cout << "Enter the index of the contact to display: ";
	int index;
	std::cin >> index;
	if (index >= 1 && index <= _NumContacts)
	{
		std::cout << "Contact information:" << std::endl;
		std::cout << "First Name: " << _Contacts[index - 1].GetFisrtName() << std::endl;
		std::cout << "Last Name: " << _Contacts[index - 1].GetLastName() << std::endl;
		std::cout << "Nickname: " << _Contacts[index - 1].GetNickame() << std::endl;
		std::cout << "Phone Number: " << _Contacts[index - 1].GetPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _Contacts[index - 1].GetDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index. Please try again." << std::endl;
}

std::string Phonebook::TruncateString(const std::string& str)
{
	if (str.length() <= 10)
		return str;
	else
		return str.substr(0, 9) + ".";
}


int	main(void)
{
	Phonebook phonebook;

	std::string input;

	while (true)
	{
		std::cout << "Enter a command: "; // Borrar
		std::cin >> input;

		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.DisplayContacts();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid input";
		std::cout << std::endl;
	}
	
}
