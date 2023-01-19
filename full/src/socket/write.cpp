/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:58 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:27:00 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <unistd.h>

//////////////////////////////////
//
//	  Socket Write Methodes
//
/////////////////////////////////

int	Socket::Write(int fd, const void *buf, size_t len)
{
	return (write(fd, buf, len));
}

int	Socket::Write(const void *buf, size_t len)
{
	return (write(this->_fd, buf, len));
}

int Socket::Write(const std::string& buf)
{
	return (write(this->_fd, buf.c_str(), buf.size()));
}

int	Socket::Write(int fd, std::string& buf)
{
	return (write(fd, buf.c_str(), buf.size()));
}
