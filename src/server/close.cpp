#include "server.hpp"
#include <iostream>

/*********************************************************************
*
* @brief    Close Server
*
* @param    void
*
* @return   0 success otherwise considered as an error 
*
*********************************************************************/
tcp_server_status_t TCPServer::Close(void)
{
	if (this->_epoll.Getfd())
		this->_epoll.Close();
	if (this->_socket.Getfd())
		this->_socket.Close();
	std::cout << "[" << this->_dt.Now("%H:%M:%S") << "] Server Closed !" << std::endl;
	return (TCP_SERVER_SUCCESS);
}
