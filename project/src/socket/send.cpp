/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:56 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:27:58 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <sys/socket.h>
#include <sys/types.h>

//////////////////////////////////
//
//	   Socket Send Methodes
//
/////////////////////////////////

ssize_t Socket::Send(int fd, const void *buf, size_t len, int flags)
{
	return (send(fd, buf, len, flags));
}

ssize_t	Socket::Send(const void *buf, size_t len, int flags)
{
	return (send(this->_fd, buf, len, flags));
}

ssize_t	Socket::Send(const std::string& buf, int flags)
{
	return (send(this->_fd, buf.c_str(), buf.size(), flags));
}

ssize_t	Socket::Send(int fd, const std::string& buf, int flags)
{
	return (send(fd, buf.c_str(), buf.size(), flags));
}

