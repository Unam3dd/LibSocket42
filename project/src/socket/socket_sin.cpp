/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_sin.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:15 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 19:02:48 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"

//////////////////////////////////
//
//	       INCLUDES
//
/////////////////////////////////

#include <cstring>

/*********************************************************************
*
* @brief	Setups the socket in Class attributes with the given parameters
*
* @param	family: AF_INET or AF_INET6
* @param	ip: const std::string& ip
* @param	port: port_t port
*
* @return	void
*
*********************************************************************/
void	Socket::SetupSin(int family, const std::string &ip, port_t port)
{
	this->_s.sin_addr.s_addr = inet_addr(ip.c_str());
	this->_s.sin_port = htons(port);
	this->_s.sin_family = family;
}

/*********************************************************************
*
* @brief	Reset the socket in Class attributes
*
* @param	void
*
* @return	void
*
*********************************************************************/
void	Socket::ResetSin(void)
{
	std::memset(&this->_s, 0, sizeof(sin_t));
}
