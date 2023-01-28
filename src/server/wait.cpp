#include "epoll.hpp"
#include "server.hpp"
#include <iostream>

/*********************************************************************
*
* @brief    Wait Server  methods
*
* 	this function wait an epoll event on server and accept new client or
* 	processes the clients data
*
* @param   void 
*
* @return   return tcp_server_status_t
*
*********************************************************************/

tcp_server_status_t	TCPServer::Wait(void)
{
	ev_t				evs[MAX_EVS];
	Socket				*ptr = NULL;
	int					efds = 0;
	int					i = 0;
	tcp_server_status_t	status = TCP_SERVER_SUCCESS;

	this->_run = 1;

	while (this->_run)
	{
		efds = this->_epoll.Wait(evs, MAX_EVS, -1);

		for (i = 0; i < efds; i++) {
			ptr = (Socket *)evs[i].data.ptr;
			
			if (ptr->Getfd() == this->_socket.Getfd()) {
				status = this->AcceptClient();
				if (status)
					std::cout << this->GetError(status) << std::endl;
			} else if (evs[i].events == EPOLLIN) {
				status = this->Handle(ptr);
				if (status)
					std::cout << this->GetError(status) << std::endl;
			}
		}
	}

	return (TCP_SERVER_SUCCESS);
}

