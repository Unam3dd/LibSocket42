/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_sin.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:15 by stales            #+#    #+#             */
/*   Updated: 2023/01/22 17:08:45 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"

//////////////////////////////////
//
//	       INCLUDES
//
/////////////////////////////////

#include <arpa/inet.h>
#include <cstring>

/*********************************************************************
*
* @brief	Setups the socket in Class attributes with the given parameters
*
* @param	family: AF_INET or AF_INET6
* @param	ip: const std::string& ip
* @param	port: port_t port
*
* @return	0 is success otherwise considered as an error
*
*********************************************************************/
int	Socket::SetupSin(int family, const std::string &ip, port_t port)
{
	this->_s.sin_addr.s_addr = this->InetAddr(ip.c_str());
	if (!this->_s.sin_addr.s_addr) return (1);
	this->_s.sin_port = htons(port);
	this->_s.sin_family = family;
	return (0);
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

/*********************************************************************
*
* @brief    Get sockaddr_in structure of Socket Instance
*
* @param    void
*
* @return    sin_t*
*
*********************************************************************/
sin_t	*Socket::GetSin(void)
{
	return (&this->_s);
}
