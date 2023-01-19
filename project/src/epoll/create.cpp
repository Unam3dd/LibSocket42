#include "epoll.hpp"
#include <sys/epoll.h>

//////////////////////////////////
//
//	       Epoll Create
//
/////////////////////////////////

int	Epoll::Create(size_t size)
{
	if (this->_isinit) return (-1);
	if ((this->_efd = epoll_create(size)) < 0)
		return (-1);
	this->_isinit = true;
	return (0);
}

int Epoll::Create(int flags)
{
	if (this->_isinit) return (-1);
	if ((this->_efd = epoll_create1(flags)) < 0)
		return (-1);
	this->_isinit = true;
	return (0);
}
