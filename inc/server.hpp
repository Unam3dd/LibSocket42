#ifndef SERVER_HPP
#define SERVER_HPP

#include "socket.hpp"
#include "epoll.hpp"

class TCPServer
{
	public:
		TCPServer(void);
		TCPServer(const std::string& host);
		TCPServer(const std::string& ip, port_t port);
		~TCPServer(void);
	protected:
	
	private:
};

#endif
