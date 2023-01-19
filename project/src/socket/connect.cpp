/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:38 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:26:39 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/socket.h>

//////////////////////////////////
//
//	   Socket Connect Methodes
//
/////////////////////////////////

int	Socket::Connect(int family, const std::string& ip, port_t port)
{
	int	n = port;

	if (ip.empty()) return (-1);

	port = (n < 0 || n > 0xFFFF) ? 0 : n;
	this->SetupSin(family, ip, port);
	if (connect(this->_fd, (struct sockaddr *)&this->_s, sizeof(this->_s)) < 0)
		return (-1);
	this->_isconnected = true;
	return (0);
}

int	Socket::Connect(int family, const std::string& address)
{
	std::string addr;
	size_t	pos = 0;
	int		n = 0;
	port_t	port = 0;

	if (address.empty()) return (-1);

	pos = address.find(':');
	if (pos == std::string::npos) return (-1);

	addr = address.substr(0, pos);
	n = std::atoi(address.substr(pos+1).c_str());
	port = (port_t)(n < 0 || n > 0xFFFF) ? 0 : n;

	this->SetupSin(family ,addr, port);

	if (connect(this->_fd, (struct sockaddr *)&this->_s, sizeof(this->_s)) < 0)
		return (-1);
	this->_isconnected = true;
	return (0);
}
