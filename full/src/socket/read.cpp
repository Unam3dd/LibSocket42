/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:28:29 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:28:30 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <unistd.h>

//////////////////////////////////
//
//	   Socket Methodes Read
//
/////////////////////////////////

int	Socket::Read(int fd, void *buf, size_t len)
{
	return (read(fd, buf, len));
}

int Socket::Read(void *buf, size_t len)
{
	return (read(this->_fd, buf, len));
}

int	Socket::Read(std::string& buf, size_t len)
{
	buf.reserve(len);
	return (read(this->_fd, (char *)buf.c_str(), buf.size()));
}

int	Socket::Read(int fd, std::string& buf, size_t len)
{
	buf.reserve(len);
	return (read(fd, (char *)buf.c_str(), buf.size()));
}
