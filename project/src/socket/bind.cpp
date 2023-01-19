/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:12 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:27:13 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstdlib>
#include <sys/socket.h>

//////////////////////////////////
//
//	    Socket Bind Methodes
//
/////////////////////////////////

int Socket::Bind(void)
{
	if (bind(this->_fd, (const sockaddr *)&this->_s, sizeof(sin_t)))
		return (-1);
	this->_isbinded = true;
	return (0);
}

int	Socket::Bind(int family, const std::string& ip, port_t port)
{
	int	n = port;

	if (ip.empty() || this->isConnected() || this->isOnListening())
		return (-1);
	
	port = (n < 0 || n > 0xFFFF) ? 0 : n;
	
	this->SetupSin(family, ip, port);
	
	if (bind(this->_fd, (const sockaddr *)&this->_s, sizeof(sin_t)))
		return (-1);

	this->_isbinded = true;
	return (0);
}

int Socket::Bind(int family, const std::string& address)
{
	std::string addr;
	size_t	pos = 0;
	int		n	= 0;
	port_t	port = 0;

	if (address.empty() || this->isConnected() || this->isOnListening())
		return (-1);
	pos = address.find(':');
	if (pos == std::string::npos) return (-1);

	addr = address.substr(0, pos);
	n = std::atoi(address.substr(pos+1).c_str());
	port = (port_t)(n < 0 || n > 0xFFFF) ? 0 : n;

	this->SetupSin(family, addr, port);

	if (bind(this->_fd, (const sockaddr *)&this->_s, sizeof(sin_t)))
		return (-1);
	this->_isbinded = true;
	return (0);
}
