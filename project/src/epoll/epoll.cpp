/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoll.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/19 17:43:14 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"
#include <unistd.h>

//////////////////////////////////
//
//	       Constructor
//
/////////////////////////////////

Epoll::Epoll(size_t size): _efd(-1), _isinit(false)
{
	if ((this->_efd = epoll_create(size) < 0))
		return ;
	this->_isinit = true;
}

Epoll::Epoll(int flags): _efd(-1), _isinit(false)
{
	if ((this->_efd = epoll_create(flags) < 0))
		return ;
	this->_isinit = true;
}

//////////////////////////////////
//
//	       Destructor
//
/////////////////////////////////

Epoll::~Epoll()
{
	if (this->_efd)
		this->Close();
	this->_isinit = false;
}

