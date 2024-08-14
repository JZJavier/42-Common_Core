/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:38:18 by pabpalma          #+#    #+#             */
/*   Updated: 2024/07/23 12:03:00 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RequestHandler.hpp"

#include "RequestHandler.hpp"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>

void handle_client_request(int client_fd) {

    size_t buffer_size = 1024;
    char buffer[buffer_size];
    std::vector<char> request_buffer;
    ssize_t bytes_read;
    ssize_t bytes_send;

    while ((bytes_read = recv(client_fd, buffer, buffer_size, 0)) > 0) {
        request_buffer.insert(request_buffer.end(), buffer, buffer + bytes_read);
		std::string request(request_buffer.begin(), request_buffer.end());
        if (request.find("\r\n\r\n") != std::string::npos) {
            break;
        }
    }

	if (bytes_read < 0) {
		std::cerr << "Error reading from socket" << std::endl; // aqui hay que devolver una pagiona con 404 info
		close(client_fd);
		return;
	}

    if (!request_buffer.empty()) {
        std::string request_str(request_buffer.begin(), request_buffer.end());
        HttpRequestParser parser;
        HttpRequest request = parser.parse(request_str);

        // Read the request body if there is one
        if (request.content_length > 0) {
            size_t header_length = request_str.find("\r\n\r\n") + 4;

            while (request_buffer.size() - header_length < request.content_length) {
                bytes_read = recv(client_fd, buffer, buffer_size, 0);
                if (bytes_read <= 0) {
                    break;
                }
                request_buffer.insert(request_buffer.end(), buffer, buffer + bytes_read);
            }

            if (request_buffer.size() > header_length) {
                request.body = std::string(request_buffer.begin() + header_length, request_buffer.end());
            }
            std::cout << "Request body:\n|||||||||||||||||||||||||||||\"" << request.body << "\"|||||||||||||||||||||||||||||"<< std::endl;
        }

        HttpResponse res_msg_obj(request, client_fd);
        std::string msg = res_msg_obj.CreateResponse();
        
        std::cout << "handle_client_request: responde_msg => +++++MSG_START+++++\"" << msg << "\"+++++MSG_END+++++\n\n";


        if ((bytes_send = send(client_fd, msg.c_str(), msg.size(), 0)) == -1)
            close (client_fd);
    }
    close(client_fd);
}


