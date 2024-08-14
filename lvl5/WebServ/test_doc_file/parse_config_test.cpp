#include "./include/Config.hpp"

int main() {
    Config config;
    config.parseConfig("./config/Linux_example_online.conf");

    for (std::vector<ServerConfig>::iterator it = config.servers.begin(); it != config.servers.end(); it ++){


		ServerConfig  s = *it;
		std::cout << "name:" << s._name << std::endl;
		std::cout << "ip:" <<  s._ip << std::endl;
		std::cout << "port:" << std::endl << "        ";
		for (std::vector<int>::iterator it = s._port.begin(); it != s._port.end(); it ++){
			std::cout << "  " << *it;
		}
		std::cout << std::endl;
		std::cout << "root:" << s._root << std::endl;
		std::cout << "index:" << s._index << std::endl;
		std::cout << "methods:" << std::endl;
		std::cout << "                        ";
		for(std::vector<std::string>::iterator it = s._methods.begin(); it != s._methods.end(); it ++)
			std::cout << "     " << (*it);
		std::cout << std::endl;
		std::cout << "client_size:" << s._client_size << std::endl; 
		std::cout << "error_page:" << std::endl << "      ";
		for (std::map<int, std::string>::iterator it = s._err_page.begin(); it != s._err_page.end(); it ++){
			std::cout << "        num:" << (*it).first << "   val:" << (*it).second;
		}
		std::cout << std::endl;
		std::cout << "location:" << std::endl;
		for (std::map<std::string, LocationConfig>::iterator it = s._location.begin(); it != s._location.end(); it ++){
			
			std::pair<std::string, LocationConfig> l = *it;
			LocationConfig							cur = l.second;

			std::cout << "              root:" << l.first << std::endl;
			std::cout << "          location: client_size:   " << cur._client_size << std::endl;
			std::cout << "          location: methods:" << std::endl;
			std::cout << "                        ";
			for(std::vector<std::string>::iterator it = cur._methods.begin(); it != cur._methods.end(); it ++)
				std::cout << "     " << (*it);
			std::cout << std::endl;
			if (cur._autoindex)
				std::cout << "           location:autoindex : on" << std::endl;
			else
				std::cout << "           location:autoindex : off" << std::endl;
			std::cout << "           location:cgi:   " << cur._cgi << std::endl;
			std::cout << "           location:index:   " << cur._index << std::endl;
			std::cout << "           location:error_page:" << std::endl << "             ";
			for (std::map<int, std::string>::iterator it = cur._err_page.begin(); it != cur._err_page.end(); it ++){
				std::cout << "        num:" << (*it).first << "   val:" << (*it).second;
			std::cout << std::endl;
			std::cout << "           location:return:" << cur._return_url << std::endl;
			}
		}
	}
    return 0;
}
