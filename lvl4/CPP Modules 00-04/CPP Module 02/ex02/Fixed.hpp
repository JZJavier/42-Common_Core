/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- < jjuarez-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:06:11 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/06/27 12:54:30 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int num);
	Fixed(const float num);
    Fixed(const Fixed &other); // Copy constructor
    Fixed& operator=(const Fixed &other); // Copy assignment operator
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    int	    toInt(void) const;
	float	toFloat(void) const;

    Fixed operator*(const Fixed &other) const; // Multiplication operator
    Fixed& operator++();                       // Pre-increment operator
    Fixed operator++(int);                     // Post-increment operator

    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

// << operator outputs Fixed objects
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif