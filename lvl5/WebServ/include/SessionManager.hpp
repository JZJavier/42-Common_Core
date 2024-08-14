/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SessionManager.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabpalma <pabpalma>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:16:02 by pabpalma          #+#    #+#             */
/*   Updated: 2024/07/26 15:37:12 by pabpalma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SESSION_MANAGER
# define SESSION_MANAGER

#include <map>
#include <string>

struct UserData {
	std::string username;
	bool 		is_logged_in;
	 UserData() : is_logged_in(false) {}
};

class SessionManager {
	private:
		std::map<std::string, UserData> sessions;
		std::string 					generate_session_id();

	public:
		std::string create_session(const UserData& user_data);
		UserData	get_user_data(const std::string& session_id);
		void		end_session(const std::string& session_id);
		bool        is_session_valid(const std::string& session_id);
};

#endif
