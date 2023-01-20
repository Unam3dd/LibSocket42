/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoll.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/20 16:32:06 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "epoll.hpp"
#include <unistd.h>

/*********************************************************************
*
* @brief	Constructor of the Epoll class / Wrapper on epoll_create
*
* @param	size: size of the epoll instance
*
* @return	void
*
*********************************************************************/
Epoll::Epoll(size_t size): _efd(-1), _isinit(false)
{
	if ((this->_efd = epoll_create(size) < 0)) return ;
	this->_isinit = true;
}

/*********************************************************************
*
* @brief	Constructor of the Epoll class / Wrapper on epoll_create1
*
* @param	flags: flag to set on the epoll instance
*
* @return	void
*
*********************************************************************/
Epoll::Epoll(int flags): _efd(-1), _isinit(false)
{
	if ((this->_efd = epoll_create(flags) < 0)) return ;
	this->_isinit = true;
}

/*********************************************************************
*
* @brief	Destructor of the Epoll class / Wrapper on close
*
* @param	void
*
* @return	void
*
*********************************************************************/
Epoll::~Epoll(void)
{
	if (this->_efd > 0)
		this->Close();
	this->_isinit = false;
}
