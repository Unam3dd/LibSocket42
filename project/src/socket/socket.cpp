/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:18 by stales            #+#    #+#             */
/*   Updated: 2023/01/20 17:22:51 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstring>
#include <sys/socket.h>

/*********************************************************************
*
* @brief	Default constructor of the class Socket. Initialize the socket 
* 			without any parameters
*
* @param	void
*
* @return	void
*
*********************************************************************/
Socket::Socket(void): _fd(-1)
{
	std::memset(&_s, 0, sizeof(sin_t));
	_iscreated = false;
	_isbinded = false;
	_isconnected = false;
	_isonlistening = false;
}

/*********************************************************************
*
* @brief	Constructor of the class Socket. Initialize the socket with
* 			the family, type and protocol given in arg
*
* @param	family: family of the socket (AF_INET, AF_INET6, AF_UNIX)
* @param	type: type of the socket (SOCK_STREAM, SOCK_DGRAM, SOCK_RAW)
* @param	proto: protocol of the socket (IPPROTO_TCP, IPPROTO_UDP, IPPROTO_RAW)
*
* @return	void
*
*********************************************************************/
Socket::Socket(int family, int type, int proto)
{
	this->_fd = socket(family, type, proto);
	_iscreated = true;
	if (this->_fd == -1)
		_iscreated = false;
	_isbinded = false;
	_isconnected = false;
	_isonlistening = false;
}

/*********************************************************************
*
* @brief	Default Destructor of the class Socket. Close the socket.
*
* @param	void
*
* @return	void
*
*********************************************************************/
Socket::~Socket(void)
{
	if (this->_fd > 0)
		this->Close(_fd);
}

/*********************************************************************
*
* @brief    Assignation Operator
*
* @param    s: Socket Instance
*
* @return    Socket
*
*********************************************************************/
Socket	&Socket::operator=(const Socket& s)
{
	this->_fd = s._fd;
	this->_isonlistening = s._isonlistening;
	this->_isbinded = s._isbinded;
	this->_isconnected = s._isconnected;
	this->_iscreated = s._iscreated;
	return (*this);
}

/*********************************************************************
*
* @brief    Compare to Socket object fd
*
* @param    s: Socket Instance
*
* @return   true if fd is the same otherwise is false 
*
*********************************************************************/
bool	Socket::operator==(Socket& s) const
{
	return (this->_fd == s._fd);
}

/*********************************************************************
*
* @brief    Copy Constructor
*
* @param    s:	Socket Instance
*
* @return    Copy of Socket Object
*
*********************************************************************/
Socket::Socket(const Socket& s)
{
	this->_fd = s._fd;
	this->_isonlistening = s._isonlistening;
	this->_isbinded = s._isbinded;
	this->_isconnected = s._isconnected;
	this->_iscreated = s._iscreated;
}
