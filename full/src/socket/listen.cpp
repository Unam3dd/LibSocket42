/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:30 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:27:31 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <sys/socket.h>

//////////////////////////////////
//
//	   Socket Listen Methodes
//
/////////////////////////////////

int	Socket::Listen(int backlog)
{
	if (listen(this->_fd, backlog))
		return (-1);
	this->_isonlistening = true;
	this->_isbinded = false;
	return (0);
}
