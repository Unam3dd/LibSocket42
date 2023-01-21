#include "socket.hpp"

/*********************************************************************
*
* @brief    Ntohs Wrapper function Convert Port Network byte order 
* 				to Host order
*
* @param    sin_port:	port in sockaddr_in
*
* @return   port to Host order
*
*********************************************************************/
port_t	Socket::Ntohs(port_t sin_port) { return (ntohs(sin_port)); }
