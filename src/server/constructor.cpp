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
}
