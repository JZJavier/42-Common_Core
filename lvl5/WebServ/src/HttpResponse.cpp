/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:49:20 by pabpalma          #+#    #+#             */
/*   Updated: 2024/08/04 00:31:23 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HttpResponse.hpp"
#include "../include/SessionManager.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include <sstream>
#include <ctime>
#include <map>
#include <iterator>


///////////////////////// BONUS
SessionManager sessionManager;


//	All_of

template <typename InputIterator, typename Predicate>
bool all_of_custom(InputIterator begin, InputIterator end, Predicate pred) {
	for (InputIterator it = begin; it != end; ++ it) {
		if (!pred(*it)) {
			return false;
		}
	}
	return true;
}

// Sends an HTTP response to the client

void sendResponse(int client_fd, const std::string& response) {
    const char* response_data = response.c_str();
    size_t total_sent = 0;
    size_t len = response.size();

    // Comprobación manual de la línea de inicio para HTTP/1.1
    if (response.size() < 8 || response.substr(0, 8) != "HTTP/1.1") {
        std::cerr << "Invalid response format. Must start with HTTP/1.1 status line.\n";
        close(client_fd);
        return;
    }

    while (total_sent < len) {
        ssize_t sent = send(client_fd, response_data + total_sent, len - total_sent, 0);
        if (sent == -1) {
            perror("send");
            close(client_fd);
            return;
        }
        total_sent += sent;
    }
}



void writeResponse(std::stringstream& response, int status_code, const std::string& status_text, const std::string& content_type, const std::string& body, const std::string& cookie_header) {
    time_t now = time(0);
    tm* gmt = gmtime(&now);
    char time_str[128];
    strftime(time_str, sizeof(time_str), "%a, %d %b %Y %H:%M:%S GMT", gmt);

    response << "HTTP/1.1 " << status_code << " " << status_text << "\r\n";
    response << "Date: " << time_str << "\r\n";
    response << "Server: MyServer/1.0\r\n";
    response << "Connection: close\r\n";
    response << "Content-Length: " << body.length() << "\r\n";
    response << "Content-Type: " << content_type << "\r\n";
    if (!cookie_header.empty()) {
        response << cookie_header << "\r\n";
    }
    response << "\r\n";
    response << body;
}

//////////////////////	BONUS

std::string 				getContentType(const std::string& file_extension){

    static std::map<std::string, std::string> content_types;
	if (content_types.empty()){

		content_types[".html"] = "text/html";
		content_types[".htm"] = "text/html";
		content_types[".txt"] = "text/plain";
		content_types[".css"] = "text/css";
		content_types[".js"] = "text/javascript";
		content_types[".json"] = "application/json";
		content_types[".xml"] = "application/xml";
		content_types[".jpg"] = "image/jpeg";
		content_types[".jpeg"] = "image/jpeg";
		content_types[".png"] = "image/png";
		content_types[".gif"] = "image/gif";
		content_types[".webp"] = "image/webp";
		content_types[".svg"] = "image/svg+xml";
		content_types[".mp3"] = "audio/mpeg";
		content_types[".ogg"] = "audio/ogg";
		content_types[".mp4"] = "video/mp4";
		content_types[".webm"] = "video/webm";
		content_types[".pdf"] = "application/pdf";
		content_types[".zip"] = "application/zip";
    }

    std::map<std::string, std::string>::iterator it = content_types.find(file_extension);
    if (it != content_types.end())
        return it->second;
    return "application/octet-stream";
}

std::string 				determineContentType(const std::string& filepath){
	
    size_t dot_pos = filepath.find_last_of(".");
    if (dot_pos == std::string::npos)
        return "application/octet-stream";

    std::string file_extension = filepath.substr(dot_pos);
    return getContentType(file_extension);
}

std::string					list_directory(const std::string &path){

	std::cout << "Start List Directory ..." << std::endl;
    std::ostringstream body;

    body << "<html><head><title>Directory listing for current path ...</title></head><body>";
    body << "<h1>Directory listing for current path ...</h1><ul>";
    DIR *dir = opendir(path.c_str());

    if (dir){

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL){

            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){

                body << "<li>" << entry->d_name << "</li>";
            }
        }
        closedir(dir);
    }else{

        body << "<li>Could not open directory</li>";
    }
    body << "</ul></body></html>";
    return body.str();
}

bool						HttpResponse::is_exist_err_page(t_status_respond page_num){

	bool	is_exist = false;
	if (!CurrentServerConfig._err_page.empty() && CurrentServerConfig._err_page.find(page_num) != CurrentServerConfig._err_page.end())
		is_exist = true;
	return is_exist;
}

static std::string			getHttpDate(){

	char		buffer[100];
	time_t		now = time(0);
	struct tm	tm = *gmtime(&now);
	strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S GMT", &tm);
	return std::string(buffer);
}

std::string					HttpResponse::loadFileContent(const std::string & url, const std::string & meth){

	std::cout << "loadFileContent: Loading file content ..." << std::endl;
	std::cout << "loadFileContent: Trying to openfile ..." << std::endl;
	std::ifstream	file(ParserURL::get_abs_url(url, CurrentServerConfig, meth).c_str());
	if (file.is_open()){

		std::cout << "loadFileContent: Start loading file content ..." << std::endl;
		std::stringstream	buffer;
		buffer << file.rdbuf();
		std::cout << "loadFileContent: File content loaded ..." << std::endl;
		return buffer.str();
	}else{
		std::cout << "loadFileContent: Open file failed ..." << std::endl;
		return "";
	}
}

void						HttpResponse::handleGet(const HttpRequest & request){

		std::string cur_url = ParserURL::get_abs_url(request.url, CurrentServerConfig, "GET");
		std::cout << "handleGet: start do the GET request..." << std::endl;

		std::cout << "handleGet: get_abs_url => \"" << cur_url << "\"" << std::endl;
		std::cout << "handleGet: request.url => \"" << request.url << "\"" << std::endl;


         std::string red_url = ParserURL::get_redireccion_url(request.url, CurrentServerConfig, "GET", CurrentPort);  
         std::cout << "handleGet: get_redireccion_url => redireccion url => \"" << red_url << "\"" << std::endl;
		 if (!red_url.empty()) {
			status_code = FOUND;
			status_text = RES_STATUS_FOUND;
			headers[CONTENT_LOCATION] = red_url;
			headers[CONTENT_SERVER] = "MyServer/1.0";
			headers[CONTENT_DATE] = getHttpDate();
			headers[CONTENT_CONNECTION] = "keep-alive";
			
			// Optionally, set the body to explain the redirection
			body = "<html><body><h1>302 Found</h1><p>Resource has moved to <a href=\"" + red_url + "\">" + red_url +     "</a></p></body></html>";
			std::stringstream ss;
			ss << body.size();
			headers[CONTENT_LENGTH] = ss.str();
			headers[CONTENT_TYPE] = getContentType(".html");
			return;
		}


		if (cur_url.find('.') == std::string::npos) {

			body = list_directory(cur_url);
			headers[CONTENT_TYPE] = getContentType(".html");
		} else {

			if (cur_url.find(".py") != std::string::npos || cur_url.find(".pl") != std::string::npos) {
				
				headers[CONTENT_TYPE] = getContentType(".html");
				body = "<html><body><h1>Result ==></h1><h2>" + run_cgi_script(cur_url) +"</h2></body></html>";
			} else {
				
		////////////////////////////////	BONUS
		// Gestionar solicitud de login
		
		
		// Gestionar solicitud de página segura

			if (request.url.find("secure_page.html") != std::string::npos) {
				std::string cookie;
				try {
					cookie = request.headers.at("Cookie");
				} catch (const std::out_of_range&) {
					std::cout << "NO COOKIES" << std::endl;
					std::stringstream response;
					defaultErrPageSet(request, NOT_ALLOWED);
					return;
				}
				
				size_t pos = cookie.find("session_id=");
				if (pos != std::string::npos) {
					size_t end = cookie.find(";", pos);
					if (end == std::string::npos) end = cookie.length();
					std::string session_id = cookie.substr(pos + 11, end - (pos + 11));
				
					if (sessionManager.is_session_valid(session_id)) {

						body = loadFileContent("/html/secure_page.html", "GET");
						if (body == "") {
							defaultErrPageSet(request, NOT_FOUND);
							return;
						}
						status_code = OK;
						status_text = RES_STATUS_OK;

						std::stringstream	ss;
						ss << body.size();
						headers[CONTENT_LENGTH] = ss.str();
						headers[CONTENT_SERVER] = "MyServer/1.0";
						headers[CONTENT_DATE] = getHttpDate();
						headers[CONTENT_CONNECTION] = "keep-alive";
						headers[CONTENT_TYPE] = getContentType(".html");

					} else {

						defaultErrPageSet(request, NOT_ALLOWED);
					}
					return;
				} else {
					// Envía una respuesta de no autorizado si no se encuentra el session_id en la cookie
					defaultErrPageSet(request, NOT_ALLOWED);
					return;
				}
			}
			(void) client_fd;
		///////////////////////////////		BONUS



				headers[CONTENT_TYPE] = getContentType(cur_url.substr(cur_url.find_last_of(".")));
				body = loadFileContent(request.url, "GET");
			}
		}
			
		//std::cout << "GET:: BODY :" << body << std::endl;
		if (body == "") {
			defaultErrPageSet(request, NOT_FOUND);
			return;
		}
		std::cout << "\n\nhandleGet: BODY CONTENT => \"" << body << "\"" << std::endl;
		status_code = OK;
		status_text = RES_STATUS_OK;

		std::stringstream	ss;
		ss << body.size();
		headers[CONTENT_LENGTH] = ss.str();
		headers[CONTENT_SERVER] = "MyServer/1.0";
		headers[CONTENT_DATE] = getHttpDate();
		headers[CONTENT_CONNECTION] = "keep-alive";
	// } catch (const std::exception & e) {

	// 	std::cout << "ERROR : " << e.what() << std::endl;
	// }
	
}


void						HttpResponse::handlePost(const HttpRequest & request){

	std::cout << "handlePost: start do the POST request..." << std::endl;
	std::string  path = ParserURL::get_abs_url(request.url, CurrentServerConfig, "POST");
	std::cout << "handlePost: get_abs_url => " << path << std::endl;
	std::cout << "handlePost: request.url => " << request.url << std::endl;


	std::cout << "handlePost: start do the mandatory part of the bonus\n";

	if (path == "" || request.headers.find("Content-Type") == request.headers.end()) {

		std::cout << "handlePost: could not find Content-Type..." << std::endl;
		defaultErrPageSet(request, NOT_FOUND);
		return;
	}
	std::map<std::string, std::string>::const_iterator it = request.headers.find("Content-Type");
   
	std::string content_type = it->second;
	if (content_type.find("multipart/form-data") == std::string::npos) {

        std::cout << "handlePost: Content-Type is not multipart/form-data..." << std::endl;
		std::cout << "handlePost: Content-Type => " << it->second << std::endl;
		std::cout << "handlePost: The body size of request is => " << request.body.size() << std::endl;


				////////////////////////////////		BONUS
		if (request.body.find("username=") != std::string::npos && request.body.find("password=") != std::string::npos) {

			std::cout << "handlePost: start do the bonus part of POST ...\n";
			std::string username;
			std::string password;
			size_t pos = request.body.find("username=");
			if (pos != std::string::npos) {
				size_t end = request.body.find("&", pos);
				username = request.body.substr(pos + 9, end - (pos + 9));
				pos = request.body.find("password=", end);
				if (pos != std::string::npos) {
					end = request.body.find("&", pos);
					if (end == std::string::npos) end = request.body.length();
					password = request.body.substr(pos + 9, end - (pos + 9));
				}
			}

			if (username.length() >= 4 && password.length() >= 4 &&
				all_of_custom(username.begin(), username.end(), ::isalnum) &&
				all_of_custom(password.begin(), password.end(), ::isalnum)) {
				
					std::cout << "ENTRA SCURE PAGE ..." << std::endl;

				UserData user_data;
				user_data.username = username;
				user_data.is_logged_in = true;
				std::string session_id = sessionManager.create_session(user_data);
				body = loadFileContent("/html/secure_page.html", "GET");
				cookie_header = "session_id=" + session_id + "; Path=/; HttpOnly";

				//std::cout << "====" << ParserURL::get_abs_url("/html/secure_page.html", CurrentServerConfig, "GET") << "====\n";


				//std::cout << "BODY_CONTENT: \"" << body << "\"" << std::endl;

				if (body == "") {
					defaultErrPageSet(request, NOT_FOUND);
					return;
				}
				status_code = OK;
				status_text = RES_STATUS_OK;

				std::stringstream	ss;
				ss << body.size();
				headers[CONTENT_LENGTH] = ss.str();
				headers[CONTENT_SERVER] = "MyServer/1.0";
				headers[CONTENT_DATE] = getHttpDate();
				headers[CONTENT_CONNECTION] = "keep-alive";
				headers[CONTENT_TYPE] = getContentType(".html");
				headers[SET_COOKIE] = cookie_header;

			} else {

				body = "Login failed";
				status_code = NOT_ALLOWED;
				status_text = RES_STATUS_NOT_ALLOWED;
				headers[CONTENT_SERVER] = "MyServer/1.0";
				headers[CONTENT_DATE] = getHttpDate();
				headers[CONTENT_TYPE] = getContentType(".html");
				headers[CONTENT_CONNECTION] = "keep-alive";
			}
			return;
		}



				//////////////////////////////			BONUS
        //defaultErrPageSet(request, NOT_FOUND);
        return;
    }
	std::string boundary = "--" + content_type.substr(content_type.find("boundary=") + 9);
    std::cout << "Boundary: " << boundary << std::endl;

	std::string req_body = request.body;
	if (req_body.empty()){
		defaultErrPageSet(request, INTERNAL_SERVER_ERROR);
		return ;
	}
    size_t boundaryPos = req_body.find(boundary);
    while (boundaryPos != std::string::npos) {
        size_t nextBoundaryPos = req_body.find(boundary, boundaryPos + boundary.size());
        std::string part = req_body.substr(boundaryPos + boundary.size(), nextBoundaryPos - (boundaryPos + boundary.size()));

        size_t contentDispPos = part.find("Content-Disposition: form-data; ");
        if (contentDispPos != std::string::npos) {
            size_t namePos = part.find("name=\"", contentDispPos);
            size_t nameEnd = part.find("\"", namePos + 6);
            std::string name = part.substr(namePos + 6, nameEnd - (namePos + 6));

            size_t filenamePos = part.find("filename=\"", contentDispPos);
            if (filenamePos != std::string::npos) {
                size_t filenameEnd = part.find("\"", filenamePos + 10);
                std::string filename = part.substr(filenamePos + 10, filenameEnd - (filenamePos + 10));

                size_t fileContentStart = part.find("\r\n\r\n", filenameEnd) + 4;
                std::string fileContent = part.substr(fileContentStart, part.find("\r\n--", fileContentStart) - fileContentStart);

                std::cout << "POST: filename: " << filename << std::endl;

                std::string filepath = path + "/" + filename;
				std::cout << "load path: " << filepath << std::endl;

                std::ofstream file(filepath.c_str(), std::ios::binary);
                if (file.is_open()) {

					std::cout << "handlePost: File opened." << std::endl;
                    file.write(fileContent.c_str(), fileContent.size());
                    file.close();
					std::cout << "handlePost: Upload sucess !!!" << std::endl;
					
					if (filename.find(".py") != std::string::npos || filename.find(".pl") != std::string::npos){
						
						body = "<html><body><h1>Result ==></h1><h2>" + run_cgi_script(filepath) +"</h2></body></html>";
						status_code = OK;
						status_text = RES_STATUS_CREATED;
						headers[CONTENT_SERVER] = "MyServer/1.0";
						headers[CONTENT_DATE] = getHttpDate();
						headers[CONTENT_CONNECTION] = "keep-alive";
						
					}else{

						defaultErrPageSet(request, OK);
					}
						
                    return;
                } else {

					std::cout << "handlePost:  File can not open." << std::endl;
					defaultErrPageSet(request, INTERNAL_SERVER_ERROR);
                    return;
                }
            }
        }

        boundaryPos = req_body.find(boundary, nextBoundaryPos);
	}
}

void						HttpResponse::handleDelete(const HttpRequest & request){

	std::cout << "DELETE: start to solve the DELETE request..." << std::endl;

	std::string	cur_url = ParserURL::get_abs_url(request.url, CurrentServerConfig, "DELETE");

	std::cout << "DELETE: absolute path -> \"" << cur_url << "\"" << std::endl; 

	struct stat file_info;

	if (stat(cur_url.c_str(), &file_info) != 0){

		std::cout << "DELETE: file does not exist..." << std::endl;
		defaultErrPageSet(request, NOT_FOUND);
		return ;
	}

	if (cur_url == ""){
		
		std::cout << "DELETE: refuse to delete the file, do not have right..." << std::endl;
		defaultErrPageSet(request, FORBIDDEN);
		return ;
	}

	if (remove(cur_url.c_str()) == 0){

		defaultErrPageSet(request, OK);
	}else {

        defaultErrPageSet(request, INTERNAL_SERVER_ERROR);
    }

	
}


HttpResponse::HttpResponse(const HttpRequest & request, int clt_fd)
    : http_version(request.http_version), status_code(OK), status_text("OK"), client_fd(clt_fd), cookie_header("") {

	// find the server config to see if it comfort those limits
	struct sockaddr_in server_addr;
    socklen_t server_addr_len = sizeof(server_addr);
    if (getsockname(clt_fd, (struct sockaddr*)&server_addr, &server_addr_len) == -1) {
        
		std::cout << "Could not find the current server ip for the request!!!!" << std::endl;
        defaultErrPageSet(request, NOT_FOUND);
        return;
    }
    std::string server_ip = inet_ntoa(server_addr.sin_addr);
	int			server_port = ntohs(server_addr.sin_port);

	std::cout << "                          port:" << server_port << std::endl;
	std::cout << "                          ip  :" << server_ip << std::endl;

	CurrentPort = server_port;
	bool is_find = false;
	for (t_config_it it = g_config.begin(); it != g_config.end(); it ++){
		
		if ((*it)._ip == server_ip && std::find((*it)._port.begin(), (*it)._port.end(), server_port) != (*it)._port.end()){
			this->CurrentServerConfig = *it;
			//std::cout << "GET: 1index_page: " << it->_index << std::endl;
			is_find = true;
			break ;
		}

		if ((*it)._ip == "0.0.0.0" && std::find((*it)._port.begin(), (*it)._port.end(), server_port) != (*it)._port.end()){
			this->CurrentServerConfig = *it;
			//std::cout << "GET: 2index_page: " << it->_index << std::endl;
			is_find = true;
			break ;
		}
	}

	if (is_find && request.headers.find("Host") != request.headers.end()){

		std::string		name = request.headers.find("Host")->second;
		if (name.find(':') == std::string::npos){
			
			for (t_config_it it = g_config.begin(); it != g_config.end(); it ++){

				if ((*it)._name == name && (*it)._ip == server_ip && std::find((*it)._port.begin(), (*it)._port.end(), server_port) != (*it)._port.end()){
					this->CurrentServerConfig = *it;
					//std::cout << "GET: 3index_page: " << it->_index << std::endl;
					break ;
				}
			}
			
		}
	}

	if (!is_find){

		std::cout << "Could not find the current server ip for the request!!!!" << std::endl;
        defaultErrPageSet(request, NOT_FOUND);
        return;
	}



	if (request.body.size() > CurrentServerConfig._client_size){

		std::cout << "Client body size is too large!!!" << std::endl;
        defaultErrPageSet(request, TOO_LARGE);
        return;
	}

	std::string 	red_url = ParserURL::get_redireccion_url(request.url, CurrentServerConfig, "GET", CurrentPort); 
	std::string     test_path = ParserURL::get_abs_url(request.url, CurrentServerConfig, request.method);
	std::cout << "\n\nHttpResponse: get_redirection_url => :   \"" << red_url << "\"" << std::endl;
	std::cout << "HttpResponse: get_absolute_url => :   \"" << test_path << "\"" << std::endl;
	std::cout << "HttpResponse: request.url => :   \"" << request.url << "\"\n" << std::endl;
	// To see if exist the url in the configfile if no it will find the url (root + filename)
	if (test_path == "" && red_url.empty()){

		std::cout << "No pass the url test, do not exist!!!" << std::endl;
        defaultErrPageSet(request, NOT_FOUND);
        return;
    }

	if (test_path == RES_STATUS_NOT_ALLOWED  && red_url.empty()){

		std::cout << "The recurse was nos allowed!!!" << std::endl;
		defaultErrPageSet(request, NOT_ALLOWED);
		return ;

	}

	std::cout << "HttpResponse: => Ready to responde thos request!!!" << std::endl;
	if(request.method == "GET")
		handleGet(request);
	else if (request.method == "POST")
		handlePost(request);
	else if (request.method == "DELETE")
		//std::cout << "Un finish DELETE method!!!" << std::endl;
		handleDelete(request);
	else
		defaultErrPageSet(request, NOT_FOUND);
}

void								HttpResponse::defaultErrPageSet(const HttpRequest & request, t_status_respond page_code){

	http_version = request.http_version;
	status_code = page_code;
	headers[CONTENT_DATE] = getHttpDate();
	headers[CONTENT_SERVER] = "MyServer/1.0";
	headers[CONTENT_TYPE] = "text/html; charset=UTF-8";
	switch (page_code)
	{
		case OK:
			status_text = RES_STATUS_OK;
			break;
		case NOT_FOUND:
			status_text = RES_STATUS_NOT_FOUND;
			break;
		case INTERNAL_SERVER_ERROR:
			status_text = RES_STATUS_CREATED;
			break;
		default:
			break;
	}

	if (is_exist_err_page(page_code)){


		std::cout << "DEFAULT ERR PAGE: page exist..." << std::endl;
		std::string path;

		if (CurrentServerConfig._root != "/")
			path = CurrentServerConfig._root + "/" + CurrentServerConfig._err_page[page_code];
		else
			path = "/" + CurrentServerConfig._err_page[page_code];
		std::ifstream	file(path.c_str());
		if (file.is_open()){
			
			std::stringstream	buffer;
			buffer << file.rdbuf();
			body = buffer.str();
		}else{

			std::stringstream ss;
			ss << page_code;
			body = "<html><body><h1> Default page. Status code:" + ss.str() + "</h1></body></html>";
		}
		std::ostringstream ss_size;
		ss_size << body.size();
		headers[CONTENT_LENGTH] = ss_size.str();
	}else{

		std::stringstream ss;
		ss << page_code;
		body = "<html><body><h1> Default page. Status code:" + ss.str() + "</h1></body></html>";
        std::ostringstream ss_size;
		ss_size << body.size();
		headers[CONTENT_LENGTH] = ss_size.str();
	}
}

std::string							HttpResponse::CreateResponse() {

    std::ostringstream response;

    response << http_version << " " << status_code << " " << status_text << "\r\n";

    for (std::map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
        response << it->first << ": " << it->second << "\r\n";

    response << "\r\n";
    response << body;
    return response.str();
}
