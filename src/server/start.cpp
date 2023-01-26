#include "server.hpp"
#include <asm-generic/socket.h>
#include <iostream>

/*********************************************************************
*
* @brief    Start Server
*
* @param    void
*
* @return    0 is success otherwise considered as an error
*
*********************************************************************/
int	TCPServer::Start(void)
{
	ev_t	ev;
	int		opt = 1;

	this->_socket.SetupSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!this->_socket.isCreated()) return (1);
	this->_socket.SetSockOpt(this->_socket.Getfd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	this->_socket.Bind(AF_INET, this->_ip, this->_port);
	if (!this->_socket.isBinded()) return (1);
	this->_socket.Listen(SOMAXCONN);
	if (!this->_socket.isOnListening()) return (1);
	this->_epoll.Create((int)0);
	if (!this->_epoll.IsInitialized()) return (1);
	ev.events = EPOLLIN;
	ev.data.ptr = (Socket *)&this->_socket;
	if (this->_epoll.Ctl(EPOLL_CTL_ADD, this->_socket.Getfd(), &ev) < 0)
		return (1);
	std::cout << "Server Started on " << this->_ip << ":" << this->_port << " !" << std::endl;
	return (0);
}
