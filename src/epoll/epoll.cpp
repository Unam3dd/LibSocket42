/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoll.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:24:47 by stales            #+#    #+#             */
/*   Updated: 2023/01/20 17:21:10 by stales           ###   ########.fr       */
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

/*********************************************************************
*
* @brief    Copy Constructor
*
* @param    e: Instance of Epoll to copy
*
* @return    Epoll Instance
*
*********************************************************************/
Epoll::Epoll(const Epoll& e)
{
	this->_efd = e._efd;
	this->_isinit = e._isinit;
	this->_init_ev = e._init_ev;
}

/*********************************************************************
*
* @brief    Assignation Operator of Epoll Instance
*
* @param    e: Instance of Epoll to assign
*
* @return    Epoll Instance
*
*********************************************************************/
Epoll	&Epoll::operator=(const Epoll& e)
{
	this->_efd = e._efd;
	this->_isinit = e._isinit;
	this->_init_ev = e._init_ev;
	return (*this);
}

/*********************************************************************
*
* @brief    Compare two Epoll Instance
*
* @param    e: Instance of Epoll to compare
*
* @return   true/false 
*
*********************************************************************/
bool	Epoll::operator==(const Epoll& e)
{
	return (this->_efd == e._efd);
}
