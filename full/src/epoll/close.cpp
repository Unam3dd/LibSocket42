/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:19 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:24:20 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"
#include <unistd.h>

//////////////////////////////////
//
//	       Close Epoll fd
//
/////////////////////////////////

int	Epoll::Close(int fd)
{
	return (close(fd));
}

int	Epoll::Close(void)
{
	if (close(this->_efd) < 0) return (-1);
	this->_efd = -1;
	return (0);
}

