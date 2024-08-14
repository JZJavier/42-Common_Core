/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SessionManager.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:20:29 by pabpalma          #+#    #+#             */
/*   Updated: 2024/07/25 18:28:40 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "SessionManager.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string SessionManager::generate_session_id() {
	std::stringstream ss;
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 8; ++i) {
		int part = rand() % 65536;
		ss << std::hex << std::setw(4) << std::setfill('0') << part;
	}
	return ss.str();
}

std::string	SessionManager::create_session(const UserData& user_data) {
	std::string session_id = generate_session_id();
	sessions[session_id] = user_data;
	return session_id;
}

UserData SessionManager::get_user_data(const std::string& session_id) {
	std::map<std::string, UserData>::iterator it = sessions.find(session_id)	;
	if (it != sessions.end()) {
		return it->second;
	}
	return UserData();
}

void SessionManager::end_session(const std::string& session_id) {
	sessions.erase(session_id);
}

bool SessionManager::is_session_valid(const std::string& session_id) {  // Añadido
    return sessions.find(session_id) != sessions.end();
}
