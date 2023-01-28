#include "server.hpp"

/*********************************************************************
*
* @brief    Map of TCPServer Status
*
* @param   nothing 
*
* @return  const std::map<tcp_server_status_t, std::string>
*
*********************************************************************/


const std::map<tcp_server_status_t, std::string>&	TCPServer::_error_table(void)
{
	static std::map<tcp_server_status_t, std::string> _maps;

	_maps[TCP_SERVER_SUCCESS] = "Server has success the last operation !";
	_maps[TCP_SERVER_ERR_CREATE] = "Server failed to create fd !";
	_maps[TCP_SERVER_ERR_BIND] = "Server failed to bind !";
	_maps[TCP_SERVER_ERR_LISTEN] = "Server failed to listen !";
	_maps[TCP_SERVER_ERR_ACCEPT] = "Server failed to accept !";
	_maps[TCP_SERVER_ERR_CLOSE] = "Server Failed to close !";
	_maps[TCP_SERVER_ERR_EPOLL] = "Epoll failed to create !";
	_maps[TCP_SERVER_ERR_EPOLL_ADD] = "Epoll failed to add new file descriptor in queue";
	_maps[TCP_SERVER_ERR_OPT] = "Server failed to set options !";

	return (_maps);
}

/*********************************************************************
*
* @brief    Get Error by status
*
* @param    status: tcp_server_status_t
*
* @return   string associated by status
*
*********************************************************************/

const std::string&	TCPServer::GetError(tcp_server_status_t status)
{
	static std::map<tcp_server_status_t, std::string> _err = this->_error_table();

	return (_err[status]);
}
