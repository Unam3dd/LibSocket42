#include "tcpserver.hpp"
#include <sys/epoll.h>
#include <unistd.h>


/*********************************************************************
*
* @brief    Setup Epoll
*
* @param    void
*
* @return   true if success otherwise considered as an error
*
*********************************************************************/
bool	TCPServer::SetupEpoll(void)
{
	ev_t	ev;

	if (this->_e.Create(0) < 0)
		return (false);

	ev.events = EPOLLIN;
	ev.data.fd = this->_s.Getfd();
	ev.data.ptr = &this->_s;
	ev.data.u32 = 0;
	ev.data.u64 = 0;

	if (this->_e.Ctl(EPOLL_CTL_ADD, ev.data.fd, &ev) < 0)
		return (false);
	return (true);
}
