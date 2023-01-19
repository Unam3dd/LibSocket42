/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:19 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 19:47:55 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"
#include <unistd.h>

/*********************************************************************
 * @brief: Close epoll fd
 *
 * @param  fd: epoll fd
 *
 * @return close(fd) result (0 if success, -1 if error)
 *
 *********************************************************************/
int	Epoll::Close(int fd)
{
	return (close(fd));
}

/*********************************************************************
* @brief: Close epoll fd
*
* @param  void: uses this->fd
*
* @return close(fd) result (0 if success, -1 if error)
*
*********************************************************************/
int	Epoll::Close(void)
{
	if (close(this->_efd) < 0) return (-1);
	this->_efd = -1;
	return (0);
}
