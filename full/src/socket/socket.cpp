/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:18 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:26:19 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstring>
#include <sys/socket.h>

//////////////////////////////////
//
//	       CONSTRUCTOR
//
/////////////////////////////////

Socket::Socket(void): _fd(-1)
{
	std::memset(&_s, 0, sizeof(sin_t));
	_iscreated = false;
	_isbinded = false;
	_isconnected = false;
	_isonlistening = false;
}

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

//////////////////////////////////
//
//	       DESTRUCTOR
//
/////////////////////////////////

Socket::~Socket(void)
{
	if (this->_fd)
		this->Close(_fd);
}
