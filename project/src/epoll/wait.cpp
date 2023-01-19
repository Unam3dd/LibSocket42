/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:25:01 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:25:03 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"

//////////////////////////////////
//
//	      Epoll Wait
//
/////////////////////////////////

int	Epoll::Wait(ev_t *events, int maxevents, int timeout)
{
	return (epoll_wait(this->_efd, events, maxevents, timeout));
}

int Epoll::Wait(int efd, ev_t *events, int maxevents, int timeout)
{
	return (epoll_wait(efd, events, maxevents, timeout));
}
