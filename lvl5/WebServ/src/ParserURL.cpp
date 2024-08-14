#include "../include/ParserURL.hpp"


static void												replace_path(std::string& str, const std::string& from, const std::string& to) {

	size_t 				start_pos = str.find(from);

	if (start_pos != std::string::npos && start_pos == 0)
		str.replace(start_pos, from.length(), to);
}

static int 												count_occurrences(const std::string& str, char ch) {

	size_t				count = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		if (*it == ch)
			++ count;
	return count;
}

t_str_keyval_map										ParserURL::get_url_key_val(const std::string & oriurl){

	t_str_keyval_map	temp;
	size_t				p_question_mark = oriurl.find('?');
	if (p_question_mark == std::string::npos)
		return temp;
	std::string		cur_url = oriurl.substr(p_question_mark + 1);
	if (cur_url.empty())
		return temp;
	std::istringstream	iss(cur_url);
	std::string			newline;
	std::string			key;
	std::string			val;
	while(std::getline(iss, newline, '&')){

		std::istringstream key_val(newline);
		if (std::getline(key_val, key, '=') && std::getline(key_val, val))
			temp[key] = val;
	}
	return temp;
}

const std::string										ParserURL::get_abs_url(std::string oriurl, const ServerConfig & curserv, const std::string & meth){

	std::cout << "get_abs_url: request method ==> " << meth << std::endl;
	std::cout << "get_abs_url: index_page => " << curserv._index << std::endl;
	t_str_vec 			serv_methods = curserv._methods;
	bool	  			is_access_servconfig = false;
	for (t_str_vec_it it = serv_methods.begin(); it != serv_methods.end(); it ++)
		if (*it == meth){
			
			is_access_servconfig = true;
			break;
		}
	if (!is_access_servconfig)
		return RES_STATUS_NOT_ALLOWED;

	t_str_vec			methods;
	bool				is_access = false;
	bool				is_loc_match = false;
	size_t				p_question_mark = oriurl.find('?');

	if(p_question_mark != std::string::npos)
		oriurl = oriurl.substr(0, p_question_mark);

	bool				is_file = false;
	size_t				p_file_mark = oriurl.find('.');
	std::string			path;
	std::string			filename;
		

	if (p_file_mark != std::string::npos){

		is_file = true;
		path = oriurl.substr(0, oriurl.find_last_of('/') + 1);
		filename = oriurl.substr(oriurl.find_last_of('/') + 1);
	}else
		path = oriurl;

	if (!curserv._location.empty()){

		std::string			match_location_path = path;
		int					path_grade = 0;
		LocationConfig		temp_loc;
		std::string			location_name;

		for(t_location_it_const it = curserv._location.begin(); it != curserv._location.end(); it ++){

			if (path.find(it->first) == 0 && count_occurrences(it->first, '/') >= path_grade){

				match_location_path = path;
				is_loc_match = true;
				if (it->first != "/"){

					path_grade = count_occurrences(it->first, '/');
					replace_path(match_location_path, it->first, it->second._root);
					temp_loc = it->second;
					methods = it->second._methods;
					location_name = it->first;
					break ;
				}else{

					match_location_path = it->second._root + path;
					methods = it->second._methods;
					temp_loc = it->second;
					location_name = it->first;
				}
			}
		}
		
		std::cout << "get_abs_url: Match location name ===> " << location_name << std::endl;
		if (!is_loc_match)
			return RES_STATUS_NOT_ALLOWED;

		//std::cout << "Is access to the location1:" << is_access << "Current meth: " << meth << std::endl;
		for (t_str_vec_it it = methods.begin(); it != methods.end(); it ++){
			if (*it == meth){
				
				//std::cout << "Methods match " << *it << " == " << meth << std::endl;
				is_access = true;
				break;
			}
			//std::cout << "Location methods : " << *it << std::endl;
		}
		//std::cout << "Is access to the location2:" << is_access << std::endl;
		if (!is_access)
			return RES_STATUS_NOT_ALLOWED;

		if(!is_file){

			if (temp_loc._autoindex == true && !temp_loc._index.empty()){

				return match_location_path + "/" + temp_loc._index;
			}
			else{

				DIR *dir = opendir(match_location_path.c_str());
				if (temp_loc._list && dir){

					closedir(dir);
					return match_location_path;
				}
				else
					return "";
			}
		} else
			return match_location_path + "/" + filename;

	} else {


		if (!curserv._root.empty()) {

			if (!curserv._index.empty() && !is_file)
				return curserv._root + "/" + oriurl + "/" + curserv._index;
			else
				return curserv._root + "/" + oriurl;
		} else {

			if (!curserv._index.empty() && !is_file)
				return oriurl + "/" + curserv._index;
			else
				return oriurl;
		}

	}

}


const std::string								ParserURL::get_redireccion_url(std::string oriurl, const ServerConfig & curserv, const std::string & meth, int curport){


	t_str_vec 			serv_methods = curserv._methods;
	bool	  			is_access_servconfig = false;
	for (t_str_vec_it it = serv_methods.begin(); it != serv_methods.end(); it ++)
		if (*it == meth){
			
			is_access_servconfig = true;
			break;
		}
	if (!is_access_servconfig)
		return "";

	bool				is_loc_match = false;
	size_t				p_question_mark = oriurl.find('?');
	if(p_question_mark != std::string::npos)
		oriurl = oriurl.substr(0, p_question_mark);

	bool				is_file = false;
	size_t				p_file_mark = oriurl.find('.');
	std::string			path;
	std::string			filename;
		

	if (p_file_mark != std::string::npos){

		is_file = true;
		path = oriurl.substr(0, oriurl.find_last_of('/') + 1);
		filename = oriurl.substr(oriurl.find_last_of('/') + 1);
	}else
		path = oriurl;

	if (!curserv._location.empty()){

		std::string			match_location_path;
		int					path_grade = 0;
		LocationConfig		temp_loc;

		for(t_location_it_const it = curserv._location.begin(); it != curserv._location.end(); it ++){

			if (path.find(it->first) == 0 && count_occurrences(it->first, '/') >= path_grade && !it->second._return_url.empty()){

				match_location_path = path;
				is_loc_match = true;
				if (it->first != "/"){

					path_grade = count_occurrences(it->first, '/');
					replace_path(match_location_path, it->first, it->second._return_url);
					temp_loc = it->second;
					break ;
				}else{

					replace_path(match_location_path, it->first, it->second._return_url);
					temp_loc = it->second;
				}
			}
		}

		if (is_loc_match){

			std::cout << "ParserURL: port => " << curserv._port[0] << std::endl; 
			std::stringstream	ss;
			ss << curport;
			std::string 		ip_port = "http://" + curserv._ip + ":" + ss.str();
				
			if(!is_file)
				return ip_port + match_location_path;
			else
				return ip_port + match_location_path + "/" + filename;
		}else
			return "";
	} else 
		return "";
}
