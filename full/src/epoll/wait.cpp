/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:25:01 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 18:37:40 by ldournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"

/*********************************************************************
*
* @brief	Wrapper on epoll_wait without epollfd
*
* @param	events: array of events to fill
* @param	maxevents: max number of events to wait for
* @param	timeout: timeout in milliseconds
*
* @return	number of events if success, -1 if error
*
*********************************************************************/
int	Epoll::Wait(ev_t *events, int maxevents, int timeout)
{
	return (epoll_wait(this->_efd, events, maxevents, timeout));
}

/*********************************************************************
*
* @brief	Wrapper on epoll_wait with epollfd
*
* @param	efd: epoll file descriptor
* @param	events: array of events to fill
* @param	maxevents: max number of events to wait for
* @param	timeout: timeout in milliseconds
*
* @return	number of events if success, -1 if error
*
*********************************************************************/
int Epoll::Wait(int efd, ev_t *events, int maxevents, int timeout)
{
	return (epoll_wait(efd, events, maxevents, timeout));
}
