#include "../include/Config.hpp"

static std::string										str_no_space(const std::string & ori){

	size_t	start = ori.find_first_not_of(' ');
	if (start == std::string::npos)
		return	ori;
	size_t	end	  = ori.find_last_not_of(' ');
	return ori.substr(start, end - start + 1);
}

static std::vector<int>									parse_port(const std::string & port_set){

	std::vector<int>	temp;
	std::string			token;
	std::stringstream	ss(port_set);

	while(std::getline(ss, token, ',')){

		int port;
		std::stringstream	convert(token);
		convert >> port;
		temp.push_back(port);
	}
	return temp;
}

LocationConfig											parseLocation(const std::string & content){

	LocationConfig				loc;
	std::string					line;
	std::istringstream	iss(content);
	while(std::getline(iss, line)){

		std::istringstream		iss_line(line);
		std::string				FWord;

		iss_line >> FWord;

		if (FWord == LOC_CLIENT_SIZE){

			long	len;

			if (!(iss_line >> len))
				throw std::runtime_error ("Error: reading client size...");
			loc._client_size = len;
		}else if (FWord == LOC_METHODS){

			std::string	 meth;
			while(iss_line >> meth)
				loc._methods.push_back(meth);
		}else if (FWord == LOC_CGI_PASS){

			std::string	 path;

			if (!(iss_line >> path))
				throw std::runtime_error("Error: reading cgi path...");
			loc._cgi = path;
		}else if (FWord == LOC_ERROR_PAGE){

			std::string	 i;
			std::string	 path;

			if (!(iss_line >> i >> path))
				throw std::runtime_error ("Error: wrong format of err_page set!!!");

			std::stringstream	tem_ss(i);
			int					pagenum;
			if (!(tem_ss >> pagenum))
				throw std::runtime_error ("Error: wrong format of err_page set!!!");
			loc._err_page[pagenum] = path;
		}else if (FWord == "return"){

			std::string  path;

			if (!(iss_line >> path))
				throw std::runtime_error ("Error: reading return path...");
			loc._return_url = path;
		}else if (FWord == LOC_AUTOINDEX){

			std::string	 stats;

			if (!(iss_line >> stats))
				throw std::runtime_error ("Error: reading autoindex status...");
			if (stats == "on")
				loc._autoindex = true;
			else if (stats == "off")
				loc._autoindex = false;
		}else if (FWord == LOC_INDEX){

			std::string  path;

			if (!(iss_line >> path))
				throw std::runtime_error ("Error: reading loc index path...");
			loc._index = path;
		}else if (FWord == LOC_ROOT){

			std::string root;
			
			if (!(iss_line >> root))
				throw std::runtime_error ("Error: reading loc root path...");
			loc._root = root;
		}else if (FWord == LOC_LIST){

			std::string	 stats;

			if (!(iss_line >> stats))
				throw std::runtime_error ("Error: reading loc list status...");
			if (stats == "on")
				loc._list = true;
			else if (stats == "off")
				loc._list = false;
		}
	}
	return loc;
}
 
std::vector<ServerConfig>                    			Config::parseConfig(const std::string & filename){

    std::ifstream               file(filename.c_str());
    if (!file.is_open()){

		throw std::runtime_error("Error: could not open the file!!!");
	}

	if (file.peek() == std::ifstream::traits_type::eof()){

		throw std::runtime_error("Error: configuration file is empty!!!");
	}
    
    std::string  				line;
    ServerConfig 				serverConfig;

    while (std::getline(file, line)){

        std::istringstream  	iss(line);
        std::string 			FWord;
		std::string				SWord;
        
		iss >> FWord >> SWord;

        if (FWord == SERV_KEY_WORD){

            if (!serverConfig._ip.empty()){

                servers.push_back(serverConfig);
                serverConfig = ServerConfig();
            }
        }else if (FWord == SERV_LISTEN){

            std::string 	cur_ip;
			size_t			start = SWord.find_first_of(':');
			
			if (start == std::string::npos)
				throw std::runtime_error("Error: wrong format in ip and port set!!!");
            cur_ip = str_no_space(SWord.substr(0, start));
            if (cur_ip == SERV_LOCALHOST)
			    serverConfig._ip = "0.0.0.0";
            else
                serverConfig._ip = cur_ip;
			serverConfig._port = parse_port(SWord.substr(start + 1));
			
		}else if (FWord == SERV_NAME){

			serverConfig._name = SWord;		
		}else if (FWord == SERV_ROOT){

			serverConfig._root = SWord;
		}else if (FWord == SERV_INDEX){

			serverConfig._index = SWord;
		}else if (FWord == SERV_METHODS){

			serverConfig._methods.push_back(SWord);
			while(iss >> SWord)
				serverConfig._methods.push_back(SWord);
		}else if (FWord == SERV_ERROR_PAGE){
			
			std::string			temp;
			if (!(iss >> temp))
				throw std::runtime_error ("Error: wrong format of err_page set!!!");
			std::stringstream	ss(SWord);
			int					pagenum;
			if (!(ss >> pagenum))
				throw std::runtime_error ("Error: wrong format of err_page set!!!");
			serverConfig._err_page[pagenum] = temp;
		}else if (FWord == SERV_CLIENT_SIZE){

			char *end;
			size_t len = std::strtol(SWord.c_str(), &end, 10);
			if (*end != '\0')
				throw std::runtime_error("Error: wrong format for the client_size!!!");
			serverConfig._client_size = len;
		}else if (FWord == SERV_LOCATION){

			if (serverConfig._ip.empty())
				throw std::runtime_error("Error: wrong format en the server setting, missing info!!!");

            std::getline(file, line, '}');
            serverConfig._location[SWord] = parseLocation(line);
        }else {
           //parseServer(iss, serverConfig);
        }

    }
    if (!serverConfig._ip.empty()){
        servers.push_back(serverConfig);
	}

	if (servers.empty())
        throw std::runtime_error("Error: no valid server configurations found!");

	return servers;
}