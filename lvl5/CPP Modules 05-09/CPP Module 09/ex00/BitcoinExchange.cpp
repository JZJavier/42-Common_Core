/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:30:39 by javier            #+#    #+#             */
/*   Updated: 2024/08/15 13:53:38 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& inputFileName) {
    std::ifstream dataFile("data.csv");
    std::ifstream inputFile(inputFileName.c_str());

    if (dataFile.is_open()) {
        std::string line;
        while (std::getline(dataFile, line)) {
            std::size_t delimiterPos = line.find(',');
            if (delimiterPos != std::string::npos) {
                std::string date = line.substr(0, delimiterPos);
                double value = std::atof(line.substr(delimiterPos + 1).c_str());
                this->insert(date, value);
            }
        }
        dataFile.close();
    } else {
        std::cerr << "Error: Could not open data file." << std::endl;
    }

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::pair<std::string, std::string> dateValuePair = split(line, '|');
            if (dateValuePair.first.empty() || dateValuePair.second.empty()) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            double value = std::atof(dateValuePair.second.c_str());
            if (value < 0 || value > 1000) {
                std::cerr << "Error: value out of range => " << line << std::endl;
                continue;
            }

            double exchangeRate = getExchangeRate(dateValuePair.first);
            if (exchangeRate > 0) {
                std::cout << trim(dateValuePair.first) << " => " << trim(dateValuePair.second) << " = " << (value * exchangeRate) << std::endl;
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Could not open input file." << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->_data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::insert(const std::string& date, double value) {
    this->_data[date] = value;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = this->_data.lower_bound(date);
    if (it == this->_data.end() || it->first != date) {
        if (it != this->_data.begin()) {
            --it;
        }
    }
    return (it != this->_data.end()) ? it->second : 0;
}

std::pair<std::string, std::string> BitcoinExchange::split(const std::string& str, char delimiter) const {
    std::size_t pos = str.find(delimiter);
    if (pos == std::string::npos) {
        return std::make_pair("", "");
    }
    return std::make_pair(trim(str.substr(0, pos)), trim(str.substr(pos + 1)));
}

std::string BitcoinExchange::trim(const std::string& str) const {
    std::size_t start = str.find_first_not_of(" \t\n\r");
    std::size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}
