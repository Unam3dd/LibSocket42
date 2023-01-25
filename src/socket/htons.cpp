#include "socket.hpp"

/*********************************************************************
*
* @brief    Wrapper of Htons Function
* 			Convert host short byte order to network byte order
*
* @param    hostshort: uint16_t
*
* @return   convert the unsigned integer hostshort from host byte order
* 			to network byte order
*
*********************************************************************/
uint16_t	Socket::Htons(uint16_t hostshort)
{
	return (htons(hostshort));
}
