/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sockopt.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:26:30 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:26:32 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "socket.hpp"

//////////////////////////////////
//
//	 Socket SockOpt Methodes
//
/////////////////////////////////

int	Socket::SetSockOpt(int fd, int lvl, int opt, const void *val, socklen_t len)
{
	return (setsockopt(fd, lvl, opt, val, len));
}

int	Socket::GetSockOpt(int fd, int lvl, int opt, void *val, socklen_t *len)
{
	return (getsockopt(fd, lvl, opt, val, len));
}
