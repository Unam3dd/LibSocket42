#include "socket.hpp"
#include <cstdlib>

/*********************************************************************
*
* @brief    Function like inet_addr reconstruct 
* 			IP address from string to unsigned integer
*
* @param    ip:	pass the string which represent IP address
*
* @return   IP Address formated on addr_t (unsigned int) 
*
*********************************************************************/
// Not Finished
addr_t	Socket::InetAddr(std::string& ip)
{
	addr_t	addr = 0;
	uint8_t	data[4] = { 0, 0, 0, 0};
	return (addr);
}
