/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockopt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:30 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:56:08 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"

/*********************************************************************
*
* @brief	Wrapper on setsockopt. Set the socket option given in arg
*
* @param	fd: socket to set
* @param	level: level of the option (SOL_SOCKET, IPPROTO_TCP, ...)
* @param	opt: option to set (SO_REUSEADDR, SO_REUSEPORT, ...)
* @param	val: const void* to the value of the option
* @param	len: size of the value of the option
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int	Socket::SetSockOpt(int fd, int lvl, int opt, const void *val, socklen_t len)
{
	return (setsockopt(fd, lvl, opt, val, len));
}

/*********************************************************************
*
* @brief	Wrapper on setsockopt. Set the socket option given in arg
*
* @param	fd: socket to set
* @param	level: level of the option (SOL_SOCKET, IPPROTO_TCP, ...)
* @param	opt: option to set (SO_REUSEADDR, SO_REUSEPORT, ...)
* @param	val: void* to the value of the option
* @param	len: size of the value of the option
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int	Socket::GetSockOpt(int fd, int lvl, int opt, void *val, socklen_t *len)
{
	return (getsockopt(fd, lvl, opt, val, len));
}
