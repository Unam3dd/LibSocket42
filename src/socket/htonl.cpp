#include "socket.hpp"

/*********************************************************************
*
* @brief    Wrapper of Htonl Function
* 			Convert host long byte order to network byte order
*
* @param    hostlong: uint32_t
*
* @return   convert the unsigned integer hostlong from host byte order
* 			to network byte order
*
*********************************************************************/
uint32_t	Socket::Htonl(uint32_t hostlong)
{
	return (htonl(hostlong));
}
