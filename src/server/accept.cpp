#include "server.hpp"
#include <iostream>

/*********************************************************************
*
* @brief   AcceptClient methods is used to accept 
* 	new incoming connection
*
* @param    nothing
*
* @return   tcp_server_status_t
*
*********************************************************************/

tcp_server_status_t	TCPServer::AcceptClient(void)
{
	Socket	*client = NULL;
	ev_t			ev;

	client = this->_socket.Accept();
	if (!client) return (TCP_SERVER_ERR_ACCEPT);
	
	std::cout << this->_dt.Now("[%H:%M:%S]") << " New Client Connected : " << client->InetNtoa(client->GetSin()->sin_addr.s_addr)
		<< ":" << client->Ntohs(client->GetSin()->sin_port) << std::endl;
	
	ev.data.ptr = (Socket *)client;
	ev.events = EPOLLIN;
	
	if (this->_epoll.Ctl(EPOLL_CTL_ADD, client->Getfd(), &ev) < 0)
		return (TCP_SERVER_ERR_EPOLL_ADD);
	std::cout << this->_dt.Now("[%H:%M:%S]") << " Client Has been added to epoll queue : " << client->InetNtoa(client->GetSin()->sin_addr.s_addr)
		<< ":" << client->Ntohs(client->GetSin()->sin_port) << std::endl;
	return (TCP_SERVER_SUCCESS);
}
