/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:28:35 by javier            #+#    #+#             */
/*   Updated: 2024/08/15 13:59:04 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdlib.h>

class BitcoinExchange 
{
	private:
		std::map<std::string, double> _data;
		void insert(const std::string& date, double value);
		double getExchangeRate(const std::string& date) const;
		std::pair<std::string, std::string> split(const std::string& str, char delimiter) const;
		std::string trim(const std::string& str) const;
	public:
		BitcoinExchange(const std::string& inputFileName);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
};

#endif
