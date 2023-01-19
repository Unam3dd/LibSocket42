/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:27 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:34:42 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"

/*********************************************************************
*
* @brief	Wrapper on epoll_ctl without epollfd
*
* @param	op: operation to perform (EPOLL_CTL_ADD, EPOLL_CTL_DEL, EPOLL_CTL_MOD)
* @param	fd: file descriptor to add to the epoll instance
* @param	event: event to add to the epoll instance
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int	Epoll::Ctl(int op, int fd, ev_t *e)
{
	return (epoll_ctl(this->_efd, op, fd, e));
}

/*********************************************************************
*
* @brief	Wrapper on epoll_ctl with epollfd
*
* @param	efd: epoll file descriptor
* @param	op: operation to perform (EPOLL_CTL_ADD, EPOLL_CTL_DEL, EPOLL_CTL_MOD)
* @param	fd: file descriptor to add to the epoll instance
* @param	event: event to add to the epoll instance
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int Epoll::Ctl(int efd, int op, int fd, ev_t *e)
{
	return (epoll_ctl(efd, op, fd, e));
}
