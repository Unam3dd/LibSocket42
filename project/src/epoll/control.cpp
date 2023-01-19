/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:27 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:24:28 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"

//////////////////////////////////
//
//	       Epoll Control
//
/////////////////////////////////

int	Epoll::Ctl(int op, int fd, ev_t *e)
{
	return (epoll_ctl(this->_efd, op, fd, e));
}

int Epoll::Ctl(int efd, int op, int fd, ev_t *e)
{
	return (epoll_ctl(efd, op, fd, e));
}
