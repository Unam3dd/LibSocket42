#include "server.hpp"

void	TCPServer::SetHost(const std::string &host)
{
	this->_host = host;
}

void	TCPServer::SetIP(const std::string& ip)
{
	this->_ip = ip;
}

void	TCPServer::SetPort(const port_t port)
{
	this->_port = port;
}

const std::string&	TCPServer::GetHost(void)
{
	return (this->_host);
}

const std::string&	TCPServer::GetIP(void)
{
	return (this->_ip);
}

const port_t&		TCPServer::GetPort(void)
{
	return (this->_port);
}
