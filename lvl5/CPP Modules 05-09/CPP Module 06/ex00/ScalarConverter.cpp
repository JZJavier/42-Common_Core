/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 05:44:09 by javier            #+#    #+#             */
/*   Updated: 2024/08/04 06:02:36 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("0")
{
}

ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	if (this != &rhs)
	{
		this->_input = rhs._input;
	}
	return *this;
}

std::string ScalarConverter::getInput() const
{
	return this->_input;
}

void ScalarConverter::setInput(std::string input)
{
	this->_input = input;
}

void ScalarConverter::convert()
{
    // Char
    try
    {
        std::cout << "char: ";
        if (this->_input.length() == 1 && !std::isdigit(this->_input[0]))
        {
            std::cout << this->_input[0] << std::endl;
        }
        else
        {
            int intValue;
            std::istringstream iss(this->_input);
            if (iss >> intValue && intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max())
            {
                if (std::isprint(intValue))
                {
                    std::cout << static_cast<char>(intValue) << std::endl;
                }
                else
                {
                    std::cout << "Non displayable" << std::endl;
                }
            }
            else
            {
                std::cout << "impossible" << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }

    // Int
    try
    {
        std::cout << "int: ";
        int intValue;
        std::istringstream iss(this->_input);
        if (iss >> intValue)
        {
            std::cout << intValue << std::endl;
        }
        else
        {
            std::cout << "impossible" << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }

    // Float
    try
    {
        std::cout << "float: ";
        if (this->_input == "nan" || this->_input == "+inf" || this->_input == "-inf")
        {
            std::cout << this->_input << "f" << std::endl;
        }
        else
        {
            float floatValue;
            std::istringstream iss(this->_input);
            if (iss >> floatValue)
            {
                std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
            }
            else
            {
                std::cout << "impossible" << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }

    // Double
    try
    {
        std::cout << "double: ";
        if (this->_input == "nan" || this->_input == "+inf" || this->_input == "-inf")
        {
            std::cout << this->_input << std::endl;
        }
        else
        {
            double doubleValue;
            std::istringstream iss(this->_input);
            if (iss >> doubleValue)
            {
                std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
            }
            else
            {
                std::cout << "impossible" << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << "impossible" << std::endl;
    }
}
