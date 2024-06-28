/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:06:14 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/27 12:47:32 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

// Shifting left by the number of fractional bits
Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _value = num << _fractionalBits;
}

// Converting float to fixed-point
Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(num * (1 << _fractionalBits)));
}

// Shifting right to get the integer part
int Fixed::toInt(void) const
{
    std::cout << "toInt member function called" << std::endl;
    return _value >> _fractionalBits;
}

// Dividing by 2^fractionalBits to get the float
float Fixed::toFloat(void) const
{
    std::cout << "toFloat member function called" << std::endl;
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}


Fixed Fixed::operator*(const Fixed &other) const
{
    std::cout << "Multiplication operator called" << std::endl;
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed& Fixed::operator++()
{
    std::cout << "Pre-increment operator called" << std::endl;
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    std::cout << "Post-increment operator called" << std::endl;
    Fixed temp = *this;
    _value++;
    return temp;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a._value > b._value) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a._value > b._value) ? a : b;
}