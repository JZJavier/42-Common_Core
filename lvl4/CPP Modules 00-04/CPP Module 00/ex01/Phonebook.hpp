/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:18:34 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/04/23 20:44:49 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact	_Contacts[8];
		int		_NumContacts;
	public:
		Phonebook();

		void		AddContact();
		void		DisplayContacts();
		std::string	TruncateString(const std::string& str);
};

#endif