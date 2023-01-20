#include "epoll.hpp"
#include <sys/epoll.h>

/*********************************************************************
*
* @brief	Wrapper on epoll_create
*
* @param	size: size of the epoll instance
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int	Epoll::Create(size_t size)
{
	if (this->_isinit) return (-1);
	if ((this->_efd = epoll_create(size)) < 0)
		return (-1);
	this->_isinit = true;
	return (0);
}

/*********************************************************************
*
* @brief	Wrapper on epoll_create1
*
* @param	flags: flag to set on the epoll instance
*
* @return	0 if success, -1 if error
*
*********************************************************************/
int Epoll::Create(int flags)
{
	if (this->_isinit) return (-1);
	if ((this->_efd = epoll_create1(flags)) < 0)
		return (-1);
	this->_isinit = true;
	return (0);
}
