/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 19:50:25 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"

/*********************************************************************
*
* @brief	Getter on _isconnected
*
* @param	void
*
* @return	0 if not _isconnected, 1 if _isconnected
*
*********************************************************************/
bool	Socket::isConnected(void)
{
	return (this->_isconnected);
}

/*********************************************************************
*
* @brief	Getter on _isonlistening
*
* @param	void
*
* @return	0 if not _isonlistening, 1 if _isonlistening
*
*********************************************************************/
bool	Socket::isOnListening(void)
{
	return (this->_isonlistening);
}

/*********************************************************************
*
* @brief	Getter on _iscreated
*
* @param	void
*
* @return	0 if not _iscreated, 1 if _iscreated
*
*********************************************************************/
bool	Socket::isCreated(void)
{
	return (this->_iscreated);
}

/*********************************************************************
*
* @brief	Getter on _isbinded
*
* @param	void
*
* @return	0 if not _isbinded, 1 if _isbinded
*
*********************************************************************/
bool	Socket::isBinded(void)
{
	return (this->_isbinded);
}

