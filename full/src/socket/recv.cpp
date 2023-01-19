/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:27:48 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstddef>
#include <sys/types.h>

//////////////////////////////////
//
//	   Socket Recv Methodes
//
/////////////////////////////////

ssize_t	Socket::Recv(int fd, void *buf, size_t len, int flags)
{
	return (recv(fd, buf, len, flags));
}

ssize_t Socket::Recv(void *buf, size_t len, int flags)
{
	return (recv(this->_fd, buf, len, flags));
}

ssize_t	Socket::Recv(std::string& buf, size_t len, int flags)
{
	if (buf.capacity() < len)
		buf.reserve(len);
	return (recv(this->_fd, (char *)buf.c_str(), len, flags));
}

ssize_t	Socket::Recv(int fd, std::string& buf, size_t len, int flags)
{
	if (buf.capacity() < len)
		buf.reserve(len);
	return (recv(fd, (char *)buf.c_str(), len, flags));
}
