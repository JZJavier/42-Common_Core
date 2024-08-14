#ifndef PARSERURL_HPP
# define PARSERURL_HPP
# include <map>
# include <vector>
# include <algorithm>
# include <iostream>
# include <sstream>
# include "Server.hpp"
# include "Config.hpp"
# define RES_STATUS_NOT_ALLOWED "not allowed"

typedef std::map<std::string, std::string>						t_str_keyval_map;
typedef t_str_keyval_map::iterator								t_str_keyval_map_it;
typedef	std::vector<std::string>								t_str_vec;
typedef	std::vector<std::string>::iterator						t_str_vec_it;

class ParserURL {

	public:

		static t_str_keyval_map									get_url_key_val(const std::string & oriurl);
		static const std::string								get_redireccion_url(std::string oriurl, const ServerConfig & curserv, const std::string & meth, int curport);
		static const std::string								get_abs_url(std::string oriurl, const ServerConfig & curserv, const std::string & meth);
};

#endif
