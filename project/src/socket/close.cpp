/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:37 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:27:38 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <unistd.h>

//////////////////////////////////
//
//	    Socket Close Methodes
//
/////////////////////////////////

int	Socket::Close(int fd)
{
	return (close(fd));
}

int Socket::Close(void)
{
	if (close(this->_fd)) return (-1);
	this->_fd = -1;
	return (0);
}
