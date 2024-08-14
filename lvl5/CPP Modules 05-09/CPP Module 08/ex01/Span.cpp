/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:50:36 by javier            #+#    #+#             */
/*   Updated: 2024/08/14 09:16:21 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _v()
{
}

Span::Span(unsigned int n) : _n(n), _v()
{
}

Span::Span(const Span &other) : _n(other._n), _v(other._v)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	_n = other._n;
	_v = other._v;
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() == _n)
		throw std::exception();
	_v.push_back(n);
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

void Span::addNumbers(int count, int maxValue)
{    
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        addNumber(rand() % maxValue);
    }
    
    return ;
}
