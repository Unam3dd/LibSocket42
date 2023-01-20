#include "socket.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

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

addr_t	Socket::InetAddr(const std::string& ip)
{
	if (ip.empty()) return (0);

	std::string	tmp = ip;
	std::string data;
	uint8_t		addr[4] = {0, 0, 0, 0};

	for (int i = 0; i < 4; i++) {
		data = tmp.substr(0, tmp.find("."));
		addr[i] = (uint8_t)std::atoi(data.c_str()) & 0xFF;
		tmp = tmp.substr(tmp.find(".")+1);
	}

	return ((addr_t)(addr[3] << 24 | addr[2] << 16 | addr[1] << 8 | addr[0]));
}
