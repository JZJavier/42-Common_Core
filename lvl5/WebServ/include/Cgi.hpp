/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javier <javier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:04:39 by javier            #+#    #+#             */
/*   Updated: 2024/07/24 21:28:09 by javier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
# define CGI_HPP

# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fstream>
# include <sstream>
# include <iostream>
# include <string>
# include <cstdlib> 
# include <cstring>
# include <sys/stat.h>
# include <fcntl.h>
# include <cerrno>
# include <string>
# include "Server.hpp"

extern char **g_envp;
std::string  run_cgi_script(const std::string& script_path);
std::string readFile(const std::string& filename);

#endif