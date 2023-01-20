/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:29 by stales            #+#    #+#             */
/*   Updated: 2023/01/20 20:24:46 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <unistd.h>

/*********************************************************************
*
* @brief    Read from fd
*
* @param    fd: Fd
* @param    buf: buf to recv data
* @param    len: size of buffer
*
* @return    bytes read or -1 if error was occured
*
*********************************************************************/
int	Socket::Read(int fd, void *buf, size_t len)
{
	return (read(fd, buf, len));
}


/*********************************************************************
*
* @brief    Read from Socket Instance
*
* @param    buf: buf to recv data
* @param    len: size of buffer
*
* @return    bytes read or -1 if error was occured
*
*********************************************************************/
int Socket::Read(void *buf, size_t len)
{
	return (read(this->_fd, buf, len));
}

/*********************************************************************
*
* @brief    Read from Socket Instance (WARNING this function reserve buf)
*
* @param    buf: buf to recv data
* @param    len: size of buffer
*
* @return    bytes read or -1 if error was occured
*
*********************************************************************/
int	Socket::Read(std::string& buf, size_t len)
{
	if (buf.capacity() < len) buf.reserve(len);
	return (read(this->_fd, (char *)buf.c_str(), buf.size()));
}

/*********************************************************************
*
* @brief    Read from fd (WARNING this function reserve buf)
*
* @param    buf: buf to recv data
* @param    len: size of buffer
*
* @return    bytes read or -1 if error was occured
*
*********************************************************************/
int	Socket::Read(int fd, std::string& buf, size_t len)
{
	if (buf.capacity() < len) buf.reserve(len);
	return (read(fd, (char *)buf.c_str(), buf.size()));
}
