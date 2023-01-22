#include "epoll.hpp"

/*********************************************************************
*
* @brief    Get Epoll File descriptor
*
* @param    void
*
* @return   Epoll File descriptor
*
*********************************************************************/
int	Epoll::Getfd(void)
{
	return (this->_efd);
}
