/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recvfrom.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:40 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:28:41 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <sys/socket.h>
#include <sys/types.h>

//////////////////////////////////
//
//	   Socket RecvFrom
//
/////////////////////////////////

ssize_t	Socket::RecvFrom(int fd, void *buf, size_t len, int flags, sin_t *sin, socklen_t *addrlen)
{
	return (recvfrom(fd, buf, len, flags, (sockaddr *)sin, addrlen));
}

ssize_t Socket::RecvFrom(void *buf, size_t len, int flags, sin_t *sin, socklen_t *addrlen)
{
	return (recvfrom(this->_fd, buf, len, flags, (sockaddr*)sin, addrlen));
}

ssize_t	Socket::RecvFrom(std::string& buf, int flags, sin_t *sin, socklen_t *addrlen)
{
	return (recvfrom(this->_fd, (char *)buf.c_str(), buf.size(), flags, (sockaddr*)sin, addrlen));
}

ssize_t	Socket::RecvFrom(int fd, std::string& buf, int flags, sin_t *sin, socklen_t *addrlen)
{
	return (recvfrom(fd, (char *)buf.c_str(), buf.size(), flags, (sockaddr*)sin, addrlen));
}
