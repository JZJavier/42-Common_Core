#include "../include/Config.hpp"
#include "../include/Server.hpp"


t_config  g_config;
char	  **g_envp;

int	main(int argc, char **argv, char **envp){

	g_envp = envp;
	std::string config_file;
	if (argc == 1)
		config_file = "./config/mac_server.conf";
	else if (argc == 2)
		config_file = argv[1];
	else{

		std::cout << "Error: Wrong arguments!!!" << std::endl;
		return 1;
	}
	std::cout << "Using configuration file: " << config_file << std::endl;

	int			count_reboot = 0;
	const int 	max_reboots = 5;
	ABORT:

		if (count_reboot < max_reboots) {

			try{
				
				Config		_config;
				g_config = _config.parseConfig(config_file);
				Server		_serv(g_config);
				_serv.start();
			}catch (const std::exception & e){

				std::cout << e.what() << std::endl;
				count_reboot ++;
				std::cout << "Server: Trying to restart... (reboot time: "<< count_reboot << ")" << std::endl;
				sleep(10);
				goto ABORT;
			}
			
		}else {
				std::cout << "Error: Maximum reboot attempt reached. Existing..." << std::endl;
				return 1;
		}

	return 0;
}
