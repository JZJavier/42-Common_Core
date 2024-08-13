/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:49:14 by javier            #+#    #+#             */
/*   Updated: 2024/08/13 12:59:12 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

template <typename T>
void iter(T *array, int length, void (*func)(T&))
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(T *array, int length, void (*func)(const T&))
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif