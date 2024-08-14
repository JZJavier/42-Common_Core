/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:57:40 by pabpalma          #+#    #+#             */
/*   Updated: 2024/08/04 01:08:41 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"


// Set file descriptor to non-blocking state
void	Server::set_nonblocking(int fd){

	int flags = fcntl(fd, F_GETFL, 0);
	if (flags == -1)
		throw std::runtime_error("fcntl F_GETFL error!!!");
	if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
		throw std::runtime_error("fcntl F_SETFL error!!!");
}

// Alternative Functions for Reducing Code
static void	err_close_throw(int sock, const std::string & info){

	close(sock);
	throw std::runtime_error(info);
}


// Load configuration file information, set up epoll event sheet and host sock

Server::Server(const std::vector<ServerConfig> &info)
    : _info(info)
#ifdef __APPLE__
    , kq(-1)
#else
    , epoll_fd(-1)
#endif
{}

Server::~Server() {
#ifdef __APPLE__
    if (kq != -1)
        close(kq);
#else
    if (epoll_fd != -1)
        close(epoll_fd);
#endif
	for (std::vector<int>::iterator it = host_socks.begin(); it != host_socks.end(); ++it) {
        if (*it != -1)
            close(*it);
    }
}

void Server::start() {
    struct sockaddr_in host_addr;

#ifdef __APPLE__
    if ((kq = kqueue()) == -1)
        throw std::runtime_error("kqueue creation error!!!");
#else
    if ((epoll_fd = epoll_create1(0)) == -1)
        throw std::runtime_error("epoll creation error!!!");
#endif

    for (std::vector<ServerConfig>::iterator its = _info.begin(); its != _info.end(); ++its) {
        for (std::vector<int>::iterator it = (*its)._port.begin(); it != (*its)._port.end(); ++it) {
            int host_sock = -1;
            if ((host_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
                throw std::runtime_error("Server start error : establishment of socket!!!");
            memset(&host_addr, 0, sizeof(host_addr));
            host_addr.sin_family = AF_INET;
            if (inet_pton(AF_INET, (*its)._ip.c_str(), &host_addr.sin_addr.s_addr) != 1)
                throw std::runtime_error("Error: transfer host ip to uint32_t!!!");
            host_addr.sin_port = htons(*it);
            
            int                yes = 1;
            setsockopt(host_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

            
            if (bind(host_sock, (struct sockaddr *)&host_addr, sizeof(host_addr)) == -1)
                err_close_throw(host_sock, "Server start error : bind!!!");

            if (listen(host_sock, 4096) == -1)
                err_close_throw(host_sock, "Server start error : listen!!!");

            set_nonblocking(host_sock);

#ifdef __APPLE__
            struct kevent event;
            EV_SET(&event, host_sock, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);

            if (kevent(kq, &event, 1, NULL, 0, NULL) == -1)
                err_close_throw(host_sock, "kevent error!!!");
#else
            struct epoll_event event;
            event.data.fd = host_sock;
            event.events = EPOLLIN | EPOLLET;

            if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, host_sock, &event) == -1)
                err_close_throw(host_sock, "epoll_ctl error!!!");
#endif
            host_socks.push_back(host_sock);
    		std::cout << "Server started successfully on port " << *it << std::endl;
        }
    }


    const int MAX_EVENTS = 10;
#ifdef __APPLE__
    struct kevent events[MAX_EVENTS];
#else
    struct epoll_event events[MAX_EVENTS];
#endif

    while (true) {
#ifdef __APPLE__
        int num_fds = kevent(kq, NULL, 0, events, MAX_EVENTS, NULL);
#else
        int num_fds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
#endif
        if (num_fds == -1)
            throw std::runtime_error("kevent/epoll_wait error!!!");

        for (int i = 0; i < num_fds; ++i) {
#ifdef __APPLE__
            if (std::find(host_socks.begin(), host_socks.end(), events[i].ident) != host_socks.end()) {
                while (true) {
                    struct sockaddr_in client_addr;
                    socklen_t client_len = sizeof(client_addr);
                    int client_fd = accept(events[i].ident, (struct sockaddr *)&client_addr, &client_len);

                    if (client_fd == -1) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK)
                            break;
                        else
                            throw std::runtime_error("accept error!!!");
                    }

                    set_nonblocking(client_fd);

                    struct kevent client_event;
                    EV_SET(&client_event, client_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);

                    if (kevent(kq, &client_event, 1, NULL, 0, NULL) == -1) {
                        close(client_fd);
                        throw std::runtime_error("kevent client add error!!!");
                    }
                }
            } else {
                handle_client_request(events[i].ident);
            }
#else
            if (std::find(host_socks.begin(), host_socks.end(), events[i].data.fd) != host_socks.end()) {
                while (true) {
                    struct sockaddr_in client_addr;
                    socklen_t client_len = sizeof(client_addr);
                    int client_fd = accept(events[i].data.fd, (struct sockaddr *)&client_addr, &client_len);

                    if (client_fd == -1) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK)
                            break;
                        else
                            throw std::runtime_error("accept error!!!");
                    }

                    set_nonblocking(client_fd);

                    struct epoll_event client_event;
                    client_event.data.fd = client_fd;
                    client_event.events = EPOLLIN | EPOLLET;

                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &client_event) == -1) {
                        close(client_fd);
                        throw std::runtime_error("epoll_ctl client add error!!!");
                    }
                }
            } else {
                handle_client_request(events[i].data.fd);
            }
#endif
        }
    }
}

