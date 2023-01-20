/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:58 by stales            #+#    #+#             */
/*   Updated: 2023/01/20 18:20:41 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <unistd.h>

/*********************************************************************
*
* @brief    Write on fd
*
* @param    fd: file descriptor
* @param    buf: buffer to write
* @param    len: size of buffer
*
* @return    bytes writes or -1 if error was occured
*
*********************************************************************/
int	Socket::Write(int fd, const void *buf, size_t len)
{
	return (write(fd, buf, len));
}

/*********************************************************************
*
* @brief    Write from Socket Instance
*
* @param    buf: buffer to write
* @param    len: size of buffer
*
* @return    bytes writes or -1 if error was occured
*
*********************************************************************/
int	Socket::Write(const void *buf, size_t len)
{
	return (write(this->_fd, buf, len));
}

/*********************************************************************
*
* @brief    Write from Socket Instance
*
* @param    buf: buffer to write
* @param    len: size of buffer
*
* @return    bytes writes or -1 if error was occured
*
*********************************************************************/
int Socket::Write(const std::string& buf)
{
	return (write(this->_fd, buf.c_str(), buf.size()));
}

/*********************************************************************
*
* @brief    Write on fd
*
* @param    buf: buffer to write
* @param    len: size of buffer
*
* @return    bytes writes or -1 if error was occured
*
*********************************************************************/
int	Socket::Write(int fd, const std::string& buf)
{
	return (write(fd, buf.c_str(), buf.size()));
}
