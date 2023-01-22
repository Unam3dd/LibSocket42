#include "tcpserver.hpp"

/*********************************************************************
*
* @brief    Setup TCPServer
*
* @param    host: const std::string& host
*
* @return   true if TCPserver was initialized otherwise is false 
*
*********************************************************************/
bool	TCPServer::SetupServer(const std::string& host)
{
	this->_s.SetupSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!this->_s.isCreated()) return (false);
	this->_s.Bind(AF_INET, host);
	if (!this->_s.isBinded()) return (false);
	this->_s.Listen(this->_maxcon);
	if (!this->_s.isOnListening()) return (false);
	return (true);
}

/*********************************************************************
*
* @brief    Setup TCPServer
*
* @param    ip: const std::string& ip
* @param	port: port_t port
*
* @return   true if TCPserver was initialized otherwise is false 
*
*********************************************************************/
bool	TCPServer::SetupServer(const std::string& ip, port_t port)
{
	this->_s.SetupSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!this->_s.isCreated()) return (false);
	this->_s.Bind(AF_INET, ip, port);
	if (!this->_s.isBinded()) return (false);
	this->_s.Listen(this->_maxcon);
	if (!this->_s.isOnListening()) return (false);
	return (true);
}

/*********************************************************************
*
* @brief    Setup TCPServer
*
* @param    host: const std::string& host
*
* @return   true if TCPserver was initialized otherwise is false 
*
*********************************************************************/
bool	TCPServer::SetupServer(const std::string& host, tcp_flags_t flags)
{
	int	opt = 1;
	int ropt = 0;

	this->_s.SetupSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!this->_s.isCreated()) return (false);
	if (flags & TCP_REUSEADDR)
		ropt = this->_s.SetSockOpt(this->_s.Getfd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
	if (ropt < 0) return (false);
	this->_s.Bind(AF_INET, host);
	if (!this->_s.isBinded()) return (false);
	this->_s.Listen(this->_maxcon);
	if (!this->_s.isOnListening()) return (false);
	return (true);
}

/*********************************************************************
*
* @brief    Setup TCPServer
*
* @param    host: const std::string& host
*
* @return   true if TCPserver was initialized otherwise is false 
*
*********************************************************************/
bool	TCPServer::SetupServer(const std::string& ip, port_t port, tcp_flags_t flags)
{
	int	opt = 1;
	int ropt = 0;

	this->_s.SetupSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (!this->_s.isCreated()) return (false);
	if (flags & TCP_REUSEADDR)
		ropt = this->_s.SetSockOpt(this->_s.Getfd(), SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
	if (ropt < 0) return (false);
	this->_s.Bind(AF_INET, ip, port);
	if (!this->_s.isBinded()) return (false);
	this->_s.Listen(this->_maxcon);
	if (!this->_s.isOnListening()) return (false);
	return (true);
}
