#include "server.hpp"

/*********************************************************************
*
* @brief    Default Constructor
*
* @param    void
*
* @return   nothing
*
*********************************************************************/
TCPServer::TCPServer(void): _port(0)
{
	this->_run = 0;
}

/*********************************************************************
*
* @brief    Copy Constructor
*
* @param    cpy: const TCPServer&
*
* @return   nothing
*
*********************************************************************/
TCPServer::TCPServer(const TCPServer& cpy) { *this = cpy; }

/*********************************************************************
*
* @brief    Assignation Constructor
*
* @param    cpy: const TCPServer&
*
* @return   TCPServer Object
*
*********************************************************************/

TCPServer	&TCPServer::operator=(const TCPServer& cpy)
{
	this->_callbacks = cpy._callbacks;
	this->_ip = cpy._ip;
	this->_port = cpy._port;
	this->_host = cpy._host;
	this->_socket = cpy._socket;
	this->_epoll = cpy._epoll;
	this->_clients = cpy._clients;
	return (*this);
}

/*********************************************************************
*
* @brief    Default Destructor
*
* @param    void
*
* @return   nothing
*
*********************************************************************/
TCPServer::~TCPServer(void) {}

