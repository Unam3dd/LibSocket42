#include "tcpserver.hpp"

/*********************************************************************
*
* @brief    Implementations shall support values of backlog up to SOMAXCONN
*
* @param    backlog: uint32_t n
*
* @return   nothing 
*
*********************************************************************/
void	TCPServer::SetMaxCon(uint32_t backlog)
{
	this->_maxcon = backlog;
}

/*********************************************************************
*
* @brief    Get Max Con Of TCPServer Instance
*
* @param    void
*
* @return   _maxcon attribute in TCPServer class 
*
*********************************************************************/
uint32_t	TCPServer::GetMaxCon(void) { return (this->_maxcon); }
