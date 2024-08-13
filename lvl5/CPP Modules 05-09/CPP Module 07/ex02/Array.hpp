/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:21:49 by javier            #+#    #+#             */
/*   Updated: 2024/08/13 13:23:36 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		~Array();
		Array &operator=(const Array &other);
		T &operator[](unsigned int index);
		unsigned int size() const;
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return (*this);
	delete [] _array;
	_array = new T[other._size];
	_size = other._size;
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif
