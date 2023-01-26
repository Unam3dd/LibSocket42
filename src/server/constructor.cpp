#include "server.hpp"
#include <iostream>

/*********************************************************************
*
* @brief    Host Constructor Server
*
* @param    host: const std::string&
*
* @return   nothing
*
*********************************************************************/
TCPServer::TCPServer(const std::string& host)
{
	if (host.empty()) {
		std::cout << "Please Enter a valid host like this : <ip>:<port> !" << std::endl;
		return ;
	}

	this->SetHost(host);
	std::cout << "[" << _dt.Now()  << "] Host was set !" << std::endl;
}

/*********************************************************************
*
* @brief    IP And Port Constructor Server
*
* @param    ip:	 	const std::string&
* @param	port:	const port_t
*
* @return   nothing
*
*********************************************************************/
TCPServer::TCPServer(const std::string& ip, port_t port)
{
	if (ip.empty()) {
		std::cout << "Please enter a valid IP address to bind example: 127.0.0.1 !" << std::endl;
		return ;
	}
	this->SetIP(ip);
	std::cout << "[" << _dt.Now() << "] Bind Address was set !" << std::endl;
	this->SetPort(port);
	std::cout << "[" << _dt.Now() << "] Bind Port was set !" << std::endl;
}
