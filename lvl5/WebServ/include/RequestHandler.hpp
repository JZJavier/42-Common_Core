#ifndef REQUESTHANDLER_HPP
# define REQUESTHANDLER_HPP
# include "Server.hpp"
# include "HttpRequest.hpp"
# include "HttpResponse.hpp"

void				handle_client_request(int client_fd);
#endif
