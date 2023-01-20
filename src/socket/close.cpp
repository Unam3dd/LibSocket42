/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:37 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:44:11 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <unistd.h>

/*********************************************************************
*
* @brief	Wrapper on close. Close the socket given in arg
*
* @param	fd: socket to close
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int	Socket::Close(int fd)
{
	return (close(fd));
}

/*********************************************************************
*
* @brief	Wrapper on close. Close and clear the socket in Class attributes
*
* @param	void
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int Socket::Close(void)
{
	if (close(this->_fd)) return (-1);
	this->_fd = -1;
	return (0);
}
