/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:23:50 by pabpalma          #+#    #+#             */
/*   Updated: 2024/07/20 12:40:06 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPREQUEST_HPP
# define HTTPREQUEST_HPP

# include <string>
# include <map>
# include "Server.hpp"

class HttpRequest {
	public:
		std::string method;
		std::string url;
		std::string http_version;
		std::map<std::string, std::string> headers;
		std::string body;
		size_t		content_length;
};

class HttpRequestParser {
	private:
		enum State {
			REQUEST_LINE,
			HEADERS,
			BODY
		} state;

		void parseRequestLine(const std::string &line, HttpRequest &httpRequest);
		void parseHeaderLine(const std::string &line, HttpRequest &httpRequest);

	public:
		HttpRequestParser();
		HttpRequest parse(const std::string &request);
};

#endif
