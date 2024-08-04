/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 05:44:12 by javier            #+#    #+#             */
/*   Updated: 2024/08/04 06:01:18 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		std::string _input;
	public:
		ScalarConverter();
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & rhs);
		std::string getInput() const;
		void setInput(std::string input);
		void convert();
};

#endif