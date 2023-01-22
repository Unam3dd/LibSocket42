#include "tcpserver.hpp"

/*********************************************************************
*
* @brief    Close Server aka Call Destructor
*
* @param	void
*
* @return  nothing 
*
*********************************************************************/
void	TCPServer::Close(void)
{
	this->~TCPServer();
}
