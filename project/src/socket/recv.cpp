/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:49:05 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstddef>
#include <sys/types.h>

/*********************************************************************
*
* @brief	Wrapper on recv. Receive data from the socket given in arg
*
* @param	fd: socket to receive data from
* @param	buf: buffer to store the data
* @param	len: size of the buffer
* @param	flags: flags to use
*
* @return	number of bytes received if success, -1 if error
*
*********************************************************************/
ssize_t	Socket::Recv(int fd, void *buf, size_t len, int flags)
{
	return (recv(fd, buf, len, flags));
}

/*********************************************************************
*
* @brief	Wrapper on recv. Receive data from the socket in Class attributes
*
* @param	buf: void* buffer to store the data
* @param	len: size of the buffer
* @param	flags: flags to use
*
* @return	number of bytes received if success, -1 if error
*
*********************************************************************/
ssize_t Socket::Recv(void *buf, size_t len, int flags)
{
	return (recv(this->_fd, buf, len, flags));
}

/*********************************************************************
*
* @brief	Wrapper on recv. Receive data from the socket in Class attributes
*
* @param	buf: std::string& buffer to store the data
* @param	len: size of the buffer
* @param	flags: flags to use
*
* @return	number of bytes received if success, -1 if error
*
*********************************************************************/
ssize_t	Socket::Recv(std::string& buf, size_t len, int flags)
{
	if (buf.capacity() < len)
		buf.reserve(len);
	return (recv(this->_fd, (char *)buf.c_str(), len, flags));
}

/*********************************************************************
*
* @brief	Wrapper on recv. Receive data from the socket in arg
*
* @param	fd: socket to receive data from
* @param	buf: std::string& buffer to store the data
* @param	len: size of the buffer
* @param	flags: flags to use
*
* @return	number of bytes received if success, -1 if error
*
*********************************************************************/
ssize_t	Socket::Recv(int fd, std::string& buf, size_t len, int flags)
{
	if (buf.capacity() < len)
		buf.reserve(len);
	return (recv(fd, (char *)buf.c_str(), len, flags));
}
