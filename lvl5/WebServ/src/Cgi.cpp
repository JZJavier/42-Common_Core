/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:26:45 by javier            #+#    #+#             */
/*   Updated: 2024/08/03 21:53:15 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cgi.hpp"

#define MAX_ENV_VARS 128

std::string readFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: open failed. " << strerror(errno) << std::endl;
        return "Error: open failed. ";
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

std::string  run_cgi_script(const std::string& script_path)
{
    if (chmod(script_path.c_str(), S_IRUSR | S_IWUSR | S_IXUSR) == -1) {
        std::cerr << "Error: chmod failed. " << strerror(errno) << std::endl;
        return "Error: chmod failed. ";
    }

    int fd = open("Cgi", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR | S_IXUSR);
    if (fd == -1) {
        std::cerr << "Error: open failed. " << strerror(errno) << std::endl;
        return "Error: open failed. ";
    }

    if (dup2(fd, STDOUT_FILENO) == -1) {
        std::cerr << "Error: dup2 failed. " << strerror(errno) << std::endl;
        close(fd);
        unlink("Cgi");
        return "Error: dup2 failed.";
    }

    // Sleep for a short time to avoid file being busy
    sleep(1);

    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "Error: fork failed. " << strerror(errno) << std::endl;
        return "Error: fork failed. ";
    }

    if (pid == 0) {
        char* argv[] = { const_cast<char*>(script_path.c_str()), NULL };

        if (execve(script_path.c_str(), argv, g_envp) == -1) {
            perror("execve");
            _exit(1);
        }
    } else {
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            std::cerr << "Error: waitpid failed. " << strerror(errno) << std::endl;
            return "Error: waitpid failed. ";
        }
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        {
            close(fd);
            std::string result = readFile("Cgi");
            unlink("Cgi");
            return result;
        } else {
            close(fd);
            unlink("Cgi");
            return "Error: CGI script failed.";
        }
    }
    return "Error: CGI script failed.";
}
