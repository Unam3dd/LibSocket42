/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:51:04 by stales            #+#    #+#             */
/*   Updated: 2023/01/23 13:13:16 by stales           ###   ########.fr       */
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
#include <sstream>
#include <ostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>

//////////////////////////////////
//
//	       TYPEDEFS
//
/////////////////////////////////

typedef struct sockaddr_in sin_t;
typedef u_int16_t		port_t;
typedef uint32_t		addr_t;
typedef struct protent	prot_t;
typedef unsigned char	uint8_t;

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
		Socket(const Socket& s);
		Socket	&operator=(const Socket& s);
		bool	operator==(Socket& s) const;
		int		SetupSocket(int family, int type, int proto);
		
		//////////////////////////////////
		//
		//	       Inlines
		//
		/////////////////////////////////
		
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
		//	       Write
		//
		/////////////////////////////////
		
		int		Write(int fd, const void *buf, size_t len);
		int		Write(const void *buf, size_t len);
		int		Write(const std::string& buf);
		int		Write(int fd, const std::string& buf);

		//////////////////////////////////
		//
		//	       Read
		//
		/////////////////////////////////
		
		int		Read(int fd, void *buf, size_t len);
		int		Read(void *buf, size_t len);
		int		Read(std::string& buf, size_t len);
		int		Read(int fd, std::string& buf, size_t len);

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
		
		int		SetupSin(int family, const std::string& ip, port_t port);
		void	ResetSin(void);

		//////////////////////////////////
		//
		//	       Inet Addr
		//
		/////////////////////////////////

		addr_t	InetAddr(const std::string& ip);

		//////////////////////////////////
		//
		//	       Inet Ntoa
		//
		/////////////////////////////////

		std::string	InetNtoa(addr_t addr);

		/////////////////////////////
		//
		//			Ntohs
		//
		/////////////////////////////

		port_t		Ntohs(port_t sin_port);

		//////////////////////////////////
		//
		//	       Clear
		//
		/////////////////////////////////

		void	Clear(void);

		//////////////////////////////////
		//
		//	       Protent
		//
		/////////////////////////////////

		prot_t	*GetProtoByName(const std::string& name);

		//////////////////////////////////
		//
		//	       Get Sockaddr in
		//
		/////////////////////////////////

		sin_t	*GetSin(void);

		//////////////////////////////////
		//
		//	       Fcntl Wrapper
		//
		/////////////////////////////////

		int		Fcntl(int fd, int cmd, long arg);
		int		Fcntl(int cmd, long arg);

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

		template<typename T>
		std::string			to_string(const T & value) { std::ostringstream oss; oss << value; return (oss.str()); }
		sin_t				_s;
		int					_fd;
		bool				_iscreated;
		bool				_isconnected;
		bool				_isonlistening;
		bool				_isbinded;
};

#endif
