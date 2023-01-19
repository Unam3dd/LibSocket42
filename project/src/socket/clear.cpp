/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:27:21 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:43:28 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"
#include <cstring>

/*********************************************************************
*
* @brief	Wrapper on close. Close and clear the socket
*
* @param	void
*
* @return	void
*
*********************************************************************/
void	Socket::Clear(void)
{
	if (this->_fd)
		this->Close();
	this->ResetSin();
	this->_isbinded = false;
	this->_isconnected = false;
	this->_isonlistening = false;
}

