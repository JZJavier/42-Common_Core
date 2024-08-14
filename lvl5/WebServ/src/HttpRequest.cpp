/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:37:02 by pabpalma          #+#    #+#             */
/*   Updated: 2024/08/04 13:53:54 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HttpRequest.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>

HttpRequestParser::HttpRequestParser() : state(REQUEST_LINE) {

}

HttpRequest HttpRequestParser::parse(const std::string &request) {
    HttpRequest httpRequest;
    std::istringstream request_stream(request);
    std::string line;

    httpRequest.content_length = 0;
    while (std::getline(request_stream, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r') {
            line = line.substr(0, line.size() - 1);
        }

        switch (state) {
            case REQUEST_LINE:
                parseRequestLine(line, httpRequest);
                state = HEADERS;
                break;
            case HEADERS:
                if (line.empty()) {
                    state = BODY;
                } else {
                    parseHeaderLine(line, httpRequest);
                }
                break;
            case BODY:
                httpRequest.body += line + "\r\n";
                break;
        }
    }
    return httpRequest;
}

void HttpRequestParser::parseRequestLine(const std::string &line, HttpRequest &httpRequest) {
    std::istringstream request_line_stream(line);
    if (!(request_line_stream >> httpRequest.method >> httpRequest.url >> httpRequest.http_version)) {
        throw std::runtime_error("Invalid HTTP request line");
    }
}

void HttpRequestParser::parseHeaderLine(const std::string &line, HttpRequest &httpRequest) {
    std::string::size_type colon_pos = line.find(':');
    if (colon_pos != std::string::npos) {
        std::string header_name = line.substr(0, colon_pos);
        std::string header_value = line.substr(colon_pos + 1);
        header_value = header_value.substr(header_value.find_first_not_of(" \t"));
        httpRequest.headers[header_name] = header_value;

        if (header_name == "Content-Length") {
            char *end;
            httpRequest.content_length = std::strtol(header_value.c_str(), &end, 10);
        }
    }
}

