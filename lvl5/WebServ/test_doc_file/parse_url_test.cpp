#include "./include/ParserURL.hpp"


int main(void){


	t_str_keyval_map  key_val;

	key_val = ParserURL::get_url_key_val("www.baidu.com/index.html");

	if (!key_val.empty())
		for (t_str_keyval_map_it it = key_val.begin(); it != key_val.end(); it ++)
			std::cout << "key: " << it->first << "\t" << "Val: " << it->second << std::endl;
	else
		std::cout << "Nooooooooooooooooooooooooooooooo" << std::endl;
	

	return 0;
}