/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sendto.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:05 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:28:06 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <sys/types.h>

//////////////////////////////////
//
//	       Socket Sendto
//
/////////////////////////////////

ssize_t Socket::SendTo(int fd, const void *buf, size_t len, int flags, const sin_t *sin, socklen_t addrlen)
{
	return (sendto(fd, buf, len, flags, (const sockaddr *)sin, addrlen));
}

ssize_t	Socket::SendTo(const void *buf, size_t len, int flags, const sin_t *sin, socklen_t addrlen)
{
	return (sendto(this->_fd, buf, len, flags, (const sockaddr*)sin, addrlen));
}

ssize_t	Socket::SendTo(int fd, const std::string& buf, int flags, const sin_t *sin, socklen_t addrlen)
{
	return (sendto(fd, buf.c_str(), buf.size(), flags, (const sockaddr*)sin, addrlen));
}

ssize_t	Socket::SendTo(const std::string& buf, int flags, const sin_t *sin, socklen_t addrlen)
{
	return (sendto(this->_fd, buf.c_str(), buf.size(), flags, (const sockaddr*)sin, addrlen));
}
