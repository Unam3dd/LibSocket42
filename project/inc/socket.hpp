/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:51:04 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:51:17 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
#define SOCKET_HPP

//////////////////////////////////
//
//	       INCLUDES
//
/////////////////////////////////

#include <cstddef>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

//////////////////////////////////
//
//	       TYPEDEFS
//
/////////////////////////////////

typedef struct sockaddr_in sin_t;
typedef u_int16_t		port_t;

//////////////////////////////////
//
//	       CLASS
//
/////////////////////////////////

class	Socket
{
	public:

		//////////////////////////////////
		//
		//	       Constructor
		//
		/////////////////////////////////
		
		Socket(void);
		Socket(int family, int type, int proto);
		
		//////////////////////////////////
		//
		//	       Inlines
		//
		/////////////////////////////////
		
		inline int		SetupSocket(int family, int type, int proto) { return (socket(family, type, proto)); }
		inline int		Getfd(void) { return (this->_fd); }
		inline void		Setfd(int fd) { this->_fd = fd; }
		inline void		CopySin(sin_t *sin) { this->_s = *sin; }

		//////////////////////////////////
		//
		//	       Connect
		//
		/////////////////////////////////
		
		int		Connect(int family, const std::string& ip, port_t port);
		int		Connect(int family, const std::string& address);

		//////////////////////////////////
		//
		//	       Bind
		//
		/////////////////////////////////
		
		int 	Bind(void);
		int		Bind(int family, const std::string& ip, port_t port);
		int		Bind(int family, const std::string& address);
	
		//////////////////////////////////
		//
		//	       Listen
		//
		/////////////////////////////////
		
		int		Listen(int backlog);
	
		//////////////////////////////////
		//
		//	       Accept
		//
		/////////////////////////////////
		
		Socket*	Accept(void);
		Socket* Accept(int fd);

		//////////////////////////////////
		//
		//	       Close
		//
		/////////////////////////////////
		
		int		Close(int fd);
		int		Close(void);

		//////////////////////////////////
		//
		//	       Send
		//
		/////////////////////////////////
		
		ssize_t	Send(int fd, const void *buf, size_t len, int flags);
		ssize_t	Send(const void *buf, size_t len, int flags);
		ssize_t Send(const std::string& buf, int flags);
		ssize_t	Send(int fd, const std::string& buf, int flags);

		//////////////////////////////////
		//
		//	       Recv
		//
		/////////////////////////////////
		
		ssize_t	Recv(int fd, void *buf, size_t len, int flags);
		ssize_t	Recv(void *buf, size_t len, int flags);
		ssize_t Recv(std::string& buf, size_t len, int flags);
		ssize_t Recv(int fd, std::string& buf, size_t len, int flags);

		//////////////////////////////////
		//
		//	       Sockopt
		//
		/////////////////////////////////
		
		int		SetSockOpt(int fd, int lvl, int opt, const void *val, socklen_t len);
		int		GetSockOpt(int fd, int lvl, int opt, void *val, socklen_t *len);
	
		//////////////////////////////////
		//
		//	       Bool
		//
		/////////////////////////////////
		
		bool	isConnected(void);
		bool	isOnListening(void);
		bool	isBinded(void);
		bool	isCreated(void);

		//////////////////////////////////
		//
		//	       Sin
		//
		/////////////////////////////////
		
		void	SetupSin(int family, const std::string& ip, port_t port);
		void	ResetSin(void);

		//////////////////////////////////
		//
		//	       Clear
		//
		/////////////////////////////////

		void	Clear(void);

		//////////////////////////////////
		//
		//	       Destructor
		//
		/////////////////////////////////
		
		~Socket(void);
	
	private:

		//////////////////////////////////
		//
		//	       PRIVATE
		//
		/////////////////////////////////
		
		sin_t				_s;
		int					_fd;
		bool				_iscreated;
		bool				_isconnected;
		bool				_isonlistening;
		bool				_isbinded;
};

#endif
