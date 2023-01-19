/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:30 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:45:52 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <sys/socket.h>

/*********************************************************************
*
* @brief	Wrapper on listen. Listen on the socket of Class attributes using backlog given in arg
*
* @param	backlog: number of connection to accept
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int	Socket::Listen(int backlog)
{
	if (listen(this->_fd, backlog))
		return (-1);
	this->_isonlistening = true;
	this->_isbinded = false;
	return (0);
}
