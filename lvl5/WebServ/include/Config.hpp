#ifndef CONFIG_HPP
# define CONFIG_HPP
# include <string>
# include <map>
# include <vector>
# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>
# include <fstream>
//location
# define LOC_CLIENT_SIZE "client_size"
# define LOC_METHODS "methods"
# define LOC_CGI_PASS "cgi_pass"
# define LOC_ERROR_PAGE "error_page"
# define LOC_RETURN "return"
# define LOC_AUTOINDEX "autoindex"
# define LOC_INDEX "index"
# define LOC_ROOT "root"
//server
# define SERV_KEY_WORD "server"
# define SERV_LISTEN "listen"
# define SERV_LOCALHOST "localhost"
# define SERV_NAME "server_name"
# define SERV_ROOT "root"
# define SERV_INDEX "index"
# define SERV_METHODS "methods"
# define SERV_ERROR_PAGE "error_page"
# define SERV_LOCATION "location"
# define SERV_CLIENT_SIZE "client_size"
# define LOC_LIST "list"

struct LocationConfig {

    std::string                             _root;
    size_t                                  _client_size;
    std::vector<std::string>                _methods;
    bool                                    _autoindex;
    bool                                    _list;
    std::string                             _cgi;
    std::string                             _index;
    std::map<int, std::string>              _err_page;
    std::string                             _return_url;

    LocationConfig()
        : _root(""),
          _client_size(0),
          _autoindex(false),
          _list(false),
          _cgi(""),
          _index(""),
          _return_url("")
    {}
};

struct ServerConfig {

    std::string                             _name;
    std::vector<int>                        _port;
    std::string                             _ip;
    std::string                             _root;
    std::string                             _index;
    std::vector<std::string>                _methods;
    size_t                                  _client_size;
    std::map<int, std::string>              _err_page;
    std::map<std::string, LocationConfig>   _location;

    ServerConfig()
        : _name(""),
          _port(),
          _ip(""),
          _root(""),
          _index(""),
          _methods(),
          _client_size(0),
          _err_page(),
          _location()
    {}
};

typedef std::vector<ServerConfig>                               t_config;
typedef std::vector<ServerConfig>::iterator                     t_config_it;
typedef std::map<std::string, LocationConfig>::iterator         t_location_it;
typedef std::map<std::string, LocationConfig>::const_iterator   t_location_it_const;
extern t_config                                             g_config;

class Config {

    public:
        std::vector<ServerConfig>           servers;
        std::vector<ServerConfig>           parseConfig(const std::string & filename);
        
};

#endif



