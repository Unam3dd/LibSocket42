#include "tcpserver.hpp"
#include <cstring>
#include <sys/socket.h>

/*********************************************************************
*
* @brief    Default Constructor of TCPServer run on 127.0.0.1:8080
*
* @param    void
*
* @return   nothing 
*
*********************************************************************/
TCPServer::TCPServer(void): _maxcon(SOMAXCONN)
{
	this->_isinitialized = this->SetupServer("127.0.0.1:8080", TCP_REUSEADDR);
}

/*********************************************************************
*
* @brief    Initialize TCPServer
*
* @param    host: const std::string& host Which represent ip and port separated by :
*
* @return   nothing 
*
*********************************************************************/
TCPServer::TCPServer(const std::string& host): _maxcon(SOMAXCONN)
{
	this->_isinitialized = this->SetupServer(host);
}

/*********************************************************************
*
* @brief   Initialize TCPServer 
*
* @param    ip: const std::string& ip
* @param    port: port_t port
*
* @return   nothing 
*
*********************************************************************/
TCPServer::TCPServer(const std::string& ip, port_t port): _maxcon(SOMAXCONN)
{
	this->_isinitialized = this->SetupServer(ip, port);
}

/*********************************************************************
*
* @brief   Initialize TCPServer 
*
* @param    ip: const std::string& ip
* @param    port: port_t port
* @param	flags: TCP_REUSEADDR set it with setsockopt
*
* @return   nothing 
*
*********************************************************************/
TCPServer::TCPServer(const std::string& ip, port_t port, tcp_flags_t flags): _maxcon(SOMAXCONN)
{
	this->_isinitialized = this->SetupServer(ip, port, flags);
}

/*********************************************************************
*
* @brief    Initialize TCPServer
*
* @param    host: const std::string& host Which represent ip and port separated by :
*
* @return   nothing 
*
*********************************************************************/
TCPServer::TCPServer(const std::string& host, tcp_flags_t flags): _maxcon(SOMAXCONN)
{
	this->_isinitialized = this->SetupServer(host, flags);
}

TCPServer	&TCPServer::operator=(const TCPServer& s)
{
	this->_maxcon = s._maxcon;
	this->_e = s._e;
	this->_s = s._s;
	return (*this);
}

/*********************************************************************
*
* @brief    TCPServer Destructor
*
* @param    void
*
* @return   void
*
*********************************************************************/
TCPServer::~TCPServer(void)
{
	if (this->_s.Getfd() > 0)
		this->_s.Close();
	if (this->_e.Getfd() > 0)
		this->_e.Close();
}
