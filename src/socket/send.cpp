/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:56 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:50:36 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <sys/socket.h>
#include <sys/types.h>

/*********************************************************************
*
* @brief	Wrapper on send. Send a message to the socket given in arg
*
* @param	fd: socket to send the message
* @param	buf: const void* to the message to send
* @param	len: size of the message to send
* @param	flags: flags to use
*
* @return	number of bytes sent if success, -1 if error
*
*********************************************************************/
ssize_t Socket::Send(int fd, const void *buf, size_t len, int flags)
{
	return (send(fd, buf, len, flags));
}

/*********************************************************************
*
* @brief	Wrapper on send. Send a message to the socket in Class attributes
*
* @param	buf: const void* to the message to send
* @param	len: size of the message to send
* @param	flags: flags to use
*
* @return	number of bytes sent if success, -1 if error
*
*********************************************************************/
ssize_t	Socket::Send(const void *buf, size_t len, int flags)
{
	return (send(this->_fd, buf, len, flags));
}

/*********************************************************************
*
* @brief	Wrapper on send. Send a message to the socket in Class attributes
*
* @param	buf: const std::string& to the message to send
* @param	flags: flags to use
*
* @return	number of bytes sent if success, -1 if error
*
*********************************************************************/
ssize_t	Socket::Send(const std::string& buf, int flags)
{
	return (send(this->_fd, buf.c_str(), buf.size(), flags));
}

/*********************************************************************
*
* @brief	Wrapper on send. Send a message to the socket given in arg
*
* @param	fd: socket to send the message
* @param	buf: const std::string& to the message to send
* @param	flags: flags to use
*
* @return	number of bytes sent if success, -1 if error
*
*********************************************************************/
ssize_t	Socket::Send(int fd, const std::string& buf, int flags)
{
	return (send(fd, buf.c_str(), buf.size(), flags));
}

