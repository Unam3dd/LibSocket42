/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcpserver.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:32:23 by stales            #+#    #+#             */
/*   Updated: 2023/01/22 18:57:46 by stales           ###   ########.fr       */
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

enum tcp_flags_t
{
	TCP_REUSEADDR = 1 << 0
};

class TCPServer
{
	public:
		TCPServer(void);
		TCPServer(const std::string& host);
		TCPServer(const std::string& ip, port_t port);
		TCPServer(const std::string& host, tcp_flags_t flags);
		TCPServer(const std::string& ip, port_t port, tcp_flags_t flags);
		TCPServer	&operator=(const TCPServer& s);

		uint32_t	GetMaxCon(void);
		bool		SetupServer(const std::string& host);
		bool		SetupServer(const std::string& ip, port_t port);
		bool		SetupServer(const std::string& host, tcp_flags_t flags);
		bool		SetupServer(const std::string& ip, port_t port, tcp_flags_t flags);
		bool		SetupEpoll(void);
		bool		Start(void);
		bool		Close(void);
		inline bool	IsInitialized(void) { return (this->_isinitialized); } 
		void		SetMaxCon(uint32_t backlog);

		~TCPServer(void);
	
	private:
		Socket		_s;
		Epoll		_e;
		uint32_t	_maxcon;
		bool		_isinitialized;
};

#endif
