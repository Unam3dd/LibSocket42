/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:26:48 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"

//////////////////////////////////
//
//	 Socket	Utils Methodes
//
/////////////////////////////////

bool	Socket::isConnected(void)
{
	return (this->_isconnected);
}

bool	Socket::isOnListening(void)
{
	return (this->_isonlistening);
}

bool	Socket::isCreated(void)
{
	return (this->_iscreated);
}

bool	Socket::isBinded(void)
{
	return (this->_isbinded);
}

