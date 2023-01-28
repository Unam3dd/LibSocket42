#include "server.hpp"
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
tcp_server_status_t TCPServer::Start(void)
{
	ev_t	ev;
	int		opt = 1;

	this->_socket.SetupSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!this->_socket.isCreated()) return (TCP_SERVER_ERR_CREATE);

	if (this->_socket.SetSockOpt(this->_socket.Getfd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
		return (TCP_SERVER_ERR_OPT);

	this->_socket.Bind(AF_INET, this->_ip, this->_port);
	if (!this->_socket.isBinded()) return (TCP_SERVER_ERR_BIND);

	this->_socket.Listen(SOMAXCONN);
	if (!this->_socket.isOnListening()) return (TCP_SERVER_ERR_LISTEN);
	this->_epoll.Create((int)0);
	if (!this->_epoll.IsInitialized()) return (TCP_SERVER_ERR_EPOLL);
	ev.events = EPOLLIN;
	ev.data.ptr = (Socket *)&this->_socket;
	if (this->_epoll.Ctl(EPOLL_CTL_ADD, this->_socket.Getfd(), &ev) < 0)
		return (TCP_SERVER_ERR_EPOLL_ADD);
	std::cout << this->_dt.Now("[%H:%M:%S]") << "Server Started on " << this->_ip << ":" << this->_port << " !" << std::endl;
	return (TCP_SERVER_SUCCESS);
}
