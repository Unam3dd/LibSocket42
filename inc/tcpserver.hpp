/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcpserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:32:23 by stales            #+#    #+#             */
/*   Updated: 2023/01/23 15:55:33 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

//////////////////////////////////
//
//	       INCLUDES
//
/////////////////////////////////

#include "socket.hpp"
#include "epoll.hpp"
#include <vector>
#include <map>

//////////////////////////////////
//
//	       ENUM
//
/////////////////////////////////

enum tcp_flags_t
{
	TCP_REUSEADDR 			= 1 << 0
};

//////////////////////////////////
//
//	       TCPServer Class
//
/////////////////////////////////

class TCPServer
{
	public:
		TCPServer(const std::string& host, tcp_flags_t flags);
		TCPServer(const std::string& ip, port_t port, tcp_flags_t flags);
		TCPServer	&operator=(const TCPServer& s);

		int					SetupServer(const std::string& host, tcp_flags_t flags);
		int					SetupServer(const std::string& ip, port_t port, tcp_flags_t flags);
		int					SetupEpoll(void);
		void				Close(void);
		inline bool			IsInitialized(void) { return (this->_isinitialized); } 
		uint32_t			GetMaxCon(void);
		void				SetMaxCon(uint32_t backlog);

		~TCPServer(void);
	
	private:
		std::vector<Socket*> clients;
		Socket				_s;
		Epoll				_e;
		uint32_t			_maxcon;
		bool				_isinitialized;
};

#endif
